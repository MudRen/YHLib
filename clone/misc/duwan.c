// duwan.c

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(NOR + RED "����" NOR, ({ "du wan", "du", "wan", "duwan" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", RED "����һ���ɶ��涾Һ���ƶ��ɵĶ�ҩ����������֮����\n" NOR);
                set("base_unit", "��");
                set("unit", "��");
                set("base_value", 100);
                set("base_weight", 10);
                set("poison_type", "poison");
                set("can_pour", 1);
                set("can_daub", 1);
                set("can_drug", 1);
                set("poison", ([
                        "level" : 200,
                        "id"    : "ding chunqiu",
                        "name"  : "��",
                        "duration": 15,
                ]));
                set("no_sell", 1);
                set("only_do_effect", 1);
        }
        setup();
}

int do_effect(object me)
{
        message_vision("$Nһ�������Ѷ�ҩȫ�����������С�\n", me);
        me->set_temp("die_reason", "���˶�ҩȥ���ڰ��޳���");
        me->die();

        destruct(this_object());

        return 1;
}

int query_autoload()
{
        return 1;
}

