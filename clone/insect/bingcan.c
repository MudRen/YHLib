//qingshe.c ����

#include <ansi.h>

inherit POISON_INSECT;

void create()
{
	set_name("����", ({ "bing can", "can" }) );
        set_weight(100);
	set("race", "Ұ��");
	set("age", 2);
	set("long", "һֻ��������͸��ͨ���Ĳϡ�\n");
	set("attitude", "peaceful");
	set("str", 20);
	set("con", 20);
        set("unit", "ֻ");
	set("limbs", ({ "ͷ��", "����", "β��" }) );
	set("verbs", ({ "bite" }) );

        set("insect_poison", ([
                "level"  : 400,
                "maximum": 400,
        ]));

	set("combat_exp", 100);

	setup();
}
