
#include <linux/module.h> 
#include <linux/kernel.h> 
#include <linux/init.h>

void D(void)
{
    int *p = NULL;
    int a = 6;
    printk("Function D\n");
    *p = a+5;	
}

void C(void)
{
    printk("Function C\n");
    D();	
}

void B(void)
{
    printk("Function B\n");
    C();	
}

void A(void)
{
    printk("Function A\n");
    B();	
}

int oops_init(void)
{
    printk("oops init\n");
    A();
    return 0;
}

void oops_exit(void)
{
    printk("oops exit!\n");
}

module_init(oops_init);
module_exit(oops_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Litao Wang");

