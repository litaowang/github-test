#include <linux/module.h>
#include <linux/list.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/types.h>
#include <linux/kthread.h>
#include <linux/proc_fs.h>

//#define tasklist_lock_address 0xc04f1980 
static struct proc_dir_entry *tempdir, *processinfo_file;

static int proc_read_processinfo(char *page, char **start, off_t offset,int count, int *eof, void *data)  
{
    struct task_struct *pos, *task;
    static char buf[1024*8] = {0};
    char tmp[128] = {0};
    task = &init_task; 
       if(offset  > 0){
            return 0;
    }
      memset(buf, 0, sizeof(buf));
//    read_lock(tasklist_lock_address);
        list_for_each_entry(pos, &task->tasks, tasks){
            sprintf(tmp,"%d\t\t%s\n",pos->pid, pos->comm);
        strcat(buf, tmp);

       memset(tmp, 0 ,sizeof(tmp));
    }
//    read_unlock(tasklist_lock_address);
        *start=buf;
        return strlen(buf);
}

static int __init hello_list_process(void)
{
    int rv = 0;
    printk("kernel,I am coming!...........\n");

    tempdir = proc_mkdir("mydir", NULL);
    if(tempdir == NULL){
        rv = -ENOMEM;
        return rv;
    }
    
    processinfo_file = create_proc_read_entry("processinfo", 0444, tempdir, proc_read_processinfo, NULL);
        if(processinfo_file == NULL){
                rv = -ENOMEM;
                remove_proc_entry("mydir", NULL);
        }

    printk("%s initialised\n", "mydir");
    printk("create processinfo success!\n");
    return 0;
}

static void __exit bye_list_process(void)
{    
    remove_proc_entry("processinfo", tempdir);
    remove_proc_entry("mydir", NULL);
    printk("bye kernel.......\n");
}

module_init(hello_list_process);
module_exit(bye_list_process);

MODULE_LICENSE("GPL");
