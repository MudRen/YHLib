#include <ansi.h>;

inherit NPC;
inherit F_MASTER;

mixed ask_me();

void create()
{
        set_name("����֮", ({ "hu yizhi", "hu", "yizhi" }));
        set("gender", "����");
        set("nickname", HIR "������" NOR);
        set("character", "��������");
        set("age", 37);
        set("long", @LONG
���˺������꣬ͷ�Ϲ���һΧ�׽���������
һ˫��Ь��ȫȻһ����ũģ����
LONG);
        set("attitude", "peaceful");
        set("str", 36);
        set("int", 28);
        set("con", 31);
        set("dex", 33);
    
        set("qi", 4000);
        set("max_qi", 4000);
        set("jing", 2000);
        set("max_jing", 2000);
        set("neili", 4500);
        set("max_neili", 4500);
        set("jiali", 160);
        set("combat_exp", 2000000);

        set_skill("force", 240);
        set_skill("lengyue-shengong", 240);
        set_skill("blade", 260);
        set_skill("baisheng-daofa", 260);
        set_skill("hujia-daofa", 240);
        set_skill("dodge", 240);
        set_skill("sixiang-bufa", 240);
        set_skill("parry", 240);
        set_skill("strike", 240);
        set_skill("chuncan-zhang", 240);
        set_skill("cuff", 240);
        set_skill("hujia-quan", 240);
        set_skill("literate", 180);
        set_skill("martial-cognize", 240);

        map_skill("force", "lengyue-shengong");
        map_skill("blade", "baisheng-daofa");
        map_skill("dodge", "sixiang-bufa");
        map_skill("parry", "baisheng-daofa");
        map_skill("strike", "chuncan-zhang");
        map_skill("cuff", "hujia-quan");

        prepare_skill("strike", "chuncan-zhang");
        prepare_skill("cuff",   "hujia-quan");

        create_family("�������", 13, "����");

        set("inquiry", ([
                "��ʤ����" : (: ask_me :),
                "������"   : "�������Ѿ����ˣ�������������",
                "��ԲԲ"   : "������Ҳû�ܺ���˵�ϼ��仰��",
                "��԰԰"   : "������Ҳû�ܺ���˵�ϼ��仰��",
        ]));

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
	        (: perform_action, "blade.heng" :),
	        (: perform_action, "cuff.kuai" :),
	        (: perform_action, "strike.jian" :),
	        (: perform_action, "dodge.fei" :),
	        (: exert_function, "recover" :),
	        (: exert_function, "powerup" :),
        }));

        setup();
        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

mixed ask_me()
{
        object ob, me;

        me = this_player();
        if (me->query("family/family_name") != "�������")
                return "���������ó��ı��£���Ҫ��Ҫ����������";

        return "�����ʦ��û����ô��";
}

int accept_ask(object me, string topic)
{
        switch (topic)
        {
        case "��ɨǧ��" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/baisheng-daofa/heng",
                           "name"    : "��ɨǧ��",
                           "sk1"     : "baisheng-daofa",
                           "msg1"    : "$N΢΢���˵�ͷ����$n��������"
                                       "�ֹ��˼��䣬�漴������������"
                                       "������ն�Ȼ���ʾ�˰��졣$n��"
                                       "һ��Ĭ��������ֱ��$N��ʾ����"
                                       "��ͻȻ˫��һ�����ƺ�����ѧ��"
                                       "�������µ�ͻ�ơ�",
                           "msg2"    : "�������������������������"
                                       "������ͬС�ɡ�",
                           "lv1"     : 150,
                           "force"   : 200,
                           "gongxian": 600,
                           "shen"    : 8000, ]));
                break;

        default:
                return 0;
        }
}
