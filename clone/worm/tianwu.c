inherit WORM;
#include <ansi.h>

void create()
{
        set_name(HIW "��ɽ����" NOR, ({ "yinshan tianwu", "yinshan", "tianwu" }));
        set("long", HIW "����һ������೤������һ˫���綾��򼡣\n" NOR);
        set("race", "Ұ��");
        set("age", random(10));
        set("attitude", "peaceful");

        set("max_qi", 3000);
        set("max_jing", 2000);

        set("str", 40);
        set("con", 30);
        set("limbs", ({ "ͷ��", "����", "β��" }));
        set("verbs", ({ "bite" }));

        set("worm_poison", ([
                "level"  : 200,
                "perhit" : 40,
                "remain" : 40,
                "maximum": 40,
                "supply" : 1,
        ]));

        set("combat_exp", 300000 + random(300000));

        set_temp("apply/attack", 80 + random(100));
        set_temp("apply/damage", 80 + random(100));
        set_temp("apply/armor", 150 + random(200));
        set_temp("apply/defence", 150 + random(200));
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

