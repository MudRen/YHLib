#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�ʹ�ƫ��");
        set("long", @LONG
��������Ͻ��ǵ����ŵĴ�Ѱ�������ǵ������������ģ�������Բ�
������;������������ǸϿ��뿪Ϊ�á�
LONG NOR);
        set("exits", ([
                "east" : __DIR__"hg",
        ]));
        set("objects", ([
                __DIR__"npc/yuqian1" : 2,
        ]));
        setup();
}
void init()
{
        add_action("do_body", "body");
}
int do_body(string arg)
{
        int max;
        object ob;
        ob = this_player();

        max = ob->query("max_qi");
        ob->set("eff_qi",max);
        ob->set("qi",max * 2);
        max = ob->query("max_jing");
        ob->set("eff_jing",max);
        ob->set("jing", max * 2);
        ob->set("neili",ob->query("max_neili") * 2);
        ob->set("jingli",ob->query("max_jingli"));
        max = ob->max_food_capacity();
        ob->set("food",max + random(40));
        max = ob->max_water_capacity();  
        ob->set("water",max + random(40));
        ob->clear_condition();
        return 1;
}

