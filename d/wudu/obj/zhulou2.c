#include <ansi.h>
#include <armor.h>

inherit WAIST;

void create()
{
        object ob;
        set_name("��¨", ({"zhu lou", "zhu", "lou"}));
        set_weight(300);
        set_max_encumbrance(15000);
        if (clonep())
        {
                set_default_object(__FILE__);

	        if (random(10) > 8)
		{
        	        ob = new("/clone/worm/obj/dunang");
                	ob->move(this_object());

        	        ob = new("/clone/worm/obj/dunang");
                	ob->move(this_object());

        	        ob = new("/clone/worm/obj/dunang");
                	ob->move(this_object());

	                ob = new(__DIR__"duanchang");
        	        ob->move(this_object());

	                ob = new(__DIR__"duanchang");
        	        ob->move(this_object());

	                ob = new(__DIR__"qianrizui");
        	        ob->move(this_object());

	                ob = new(__DIR__"qianrizui");
        	        ob->move(this_object());

	                ob = new(__DIR__"fugu");
        	        ob->move(this_object());

	                ob = new(__DIR__"chuanxin");
        	        ob->move(this_object());

	                ob = new(__DIR__"shexinzi");
        	        ob->move(this_object());
		} else
	        if (random(10) > 6)
		{
        	        ob = new("/clone/worm/obj/dunang");
                	ob->move(this_object());

        	        ob = new("/clone/worm/obj/dunang");
                	ob->move(this_object());

	                ob = new(__DIR__"duanchang");
        	        ob->move(this_object());

	                ob = new(__DIR__"qianrizui");
        	        ob->move(this_object());

	                ob = new(__DIR__"fugu");
        	        ob->move(this_object());

	                ob = new(__DIR__"chuanxin");
        	        ob->move(this_object());
		} else
	        if (random(10) > 4)
		{
        	        ob = new("/clone/worm/obj/dunang");
                	ob->move(this_object());

	                ob = new(__DIR__"qianrizui");
        	        ob->move(this_object());

	                ob = new(__DIR__"chuanxin");
        	        ob->move(this_object());
		} else
		{
	                ob = new(__DIR__"qianrizui");
        	        ob->move(this_object());

	                ob = new(__DIR__"chuanxin");
        	        ob->move(this_object());
		}
        } else
        {
                set("unit", "��");
                set("long", "����һ��С�ڴ�ǵ���¨����������Ų�ҩ��\n");
                set("wear_msg", "$N����¨���ڱ��ϡ�\n");
                set("remove_msg", "$N����¨�ӱ��Ϸ���������\n");
                set("value", 50);
                set("material", "bamboo");
                set("armor_prop/armor", 3);
        }
        setup();
}

int is_container() { return 1; }
