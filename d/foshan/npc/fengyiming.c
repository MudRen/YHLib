inherit NPC;

void create()
{
        set_name("��һ��", ({ "feng yiming", "feng", "yiming" }));
        set("long", @LONG
��һ���Ƿ�ɽ���ϴ����������֮�ӡ�ֻ����
������ݣ�����Ӣ�������������书������
LONG);
        set("title", "��ɽ�廢�Ŵ���");
        set("gender", "����");
        set("age", 25);
        set("combat_exp", 40000);
        set_skill("unarmed", 50);
        set_skill("force", 60);
        set_skill("blade", 80);
        set_skill("dodge", 50);
        set_skill("parry", 50);

        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
        set_temp("apply/armor", 5);
        set_temp("apply/damage", 10);
        setup();

        carry_object("/d/city/npc/cloth/fu-cloth")->wear();
        carry_object("/d/city/npc/cloth/jade-belt")->wear();
}
