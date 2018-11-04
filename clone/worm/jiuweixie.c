inherit WORM;
#include <ansi.h>

void create()
{
        set_name(WHT "��βЫ" NOR, ({ "jiuwei xie", "jiuwei", "xie" }));
        set("long", WHT "����һֻ���������о�ֻβ�ݵĴ�Ы�ӡ�\n" NOR);
        set("race", "Ұ��");
        set("age", random(10));
        set("attitude", "peaceful");

        set("max_qi", 2000);
        set("max_jing", 1000);

        set("str", 30);
        set("con", 30);
        set("limbs", ({ "ͷ��", "����", "β��" }));
        set("verbs", ({ "bite" }));

        set("worm_poison", ([
                "level"  : 150,
                "perhit" : 20,
                "remain" : 60,
                "maximum": 60,
                "supply" : 1,
        ]));

        set("combat_exp", 300000 + random(300000));

        set_temp("apply/attack", 180 + random(180));
        set_temp("apply/damage", 180 + random(180));
        set_temp("apply/armor", 100 + random(100));
        set_temp("apply/defence", 100 + random(100));
        setup();
}

void die()
{
        object ob;
        message_vision(HIR "\n$N" HIR "���ڵ��ϣ����ˡ�\n\n" NOR, this_object());
        ob = new(__DIR__"obj/dunang");
        ob->move(environment(this_object()));
        destruct(this_object());
}
