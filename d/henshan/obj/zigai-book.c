#include <ansi.h>
inherit ITEM;

void create()
{
    	set_name(HIY "���ϸǽ��ס�" NOR, ({ "zigai jianpu", "jianpu", "zigai", "pu"}));
        set_weight(600);
        if (clonep())
        	destruct(this_object());
        else{
        	set("unit", "��");
        	set("long", HIY "������д�����ϸǽ��ס���\n" NOR);
        	set("value", 1);
		set("no_sell", 1);
        	set("material", "paper");
        	set("skill", ([
            		"name"         :  "zigai-jian",        
            		"exp_required" :  10000,          
            		"jing_cost"    :  20,         
            		"difficulty"   :  20,
            		"max_skill"    :  120
        	]));

       }
}
