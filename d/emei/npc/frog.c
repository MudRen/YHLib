#include <ansi.h>
inherit NPC;

void create()
{
        set_name(GRN "������" NOR, ({ "frog" }));
        set("age", 7);
        set("long", GRN "����һֻ��˿�����ܣ���������յ�ˮ̶\n"
                    "�ȫ�������ʷ�׳׳��һ��Ѫ����۾�\nʮ��"
                    "���ģ�������ɱ������\n");
        set("limbs", ({ "��ǰצ", "�ܺ�ץ", "����" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("combat_exp", 50);
        set("shen_type", -1);
        set("str", 11);
        set("dex", 11);
        set("con", 11);
        set("int", 11);
        set("attitude", "peaceful");
        setup();
}
