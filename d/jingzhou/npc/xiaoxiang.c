#include <ansi.h>
inherit NPC;

void create()
{
        set_name("������", ({ "xiao xiangzi", "xiao" }));
        set("long", "������������Ϊ�����ڶ�����ѧ�ң��������īˮ�Ⱥ���Ҫ�\n");
        set("gender", "����");
        set("age", 45);

        set_skill("literate", 300);
        set_skill("taoism", 300);

        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_temp("apply/attack", 80);
        set_temp("apply/defense", 80);
        set_temp("apply/damage", 20);

        set("combat_exp", 400000);
        set("shen_type", 1);
        setup();

        set("chat_chance", 3);
        set("chat_msg", ({
                CYN "������˵��������֮�£�Ī������������֮����Ī��������\n" NOR,
                CYN "������˵���������ˣ�С�������ɣ����������δ������֮��\n" NOR,
                CYN "������˵������ѧ֮�����������¡���������ֹ�����ơ� \n" NOR,
                CYN "������˵����������֪���������ģ�������ң��ι�ƽ���¡�\n" NOR,
        }) );
        carry_object("/clone/misc/cloth")->wear();
}
