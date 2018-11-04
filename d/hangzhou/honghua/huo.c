#include <ansi.h>

inherit NPC;
inherit F_MASTER;

mixed ask_skill1();

void create()
{
        set_name("����ͩ", ({ "huo qingtong", "huo", "qingtong" }));
        set("long", @LONG
��Ů��������͸��һ��Ӣ����������ˣ�����
������÷��ѩ��������ޥ��˪���������ڣ�ϼ
ӳ������˫Ŀ���������亮��������ذ�ף���
�洹�磬������ӣ�ͷ����˿���Сñ��ñ��
���˸������Ĵ�����ë�������������续��
LONG);
        set("nickname", HIG "�������" NOR);
        set("gender", "Ů��");
        set("class", "swordsman");
        set("age", 18);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("per", 30);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        
        set("max_qi", 2800);
        set("max_jing", 1500);
        set("neili", 2500);
        set("max_neili", 2500);
        set("jiali", 150);
        set("combat_exp", 800000);

        set_skill("force", 180);
        set_skill("zhanshen-xinjing", 100);
        set_skill("tianchi-neigong", 180);
        set_skill("dodge", 180);
        set_skill("yanzi-chuanyun", 160);
        set_skill("zhuangzi-wu", 180);
        set_skill("parry", 160);
        set_skill("sword", 180);
        set_skill("sanfen-jianshu", 180);
        set_skill("hand", 160);
        set_skill("yunlong-shou", 160);
        set_skill("claw", 160);
        set_skill("yunlong-zhua", 160);
        set_skill("martial-cognize", 160);
        set_skill("literate", 200);
        set_skill("muslim", 300);

        map_skill("force", "tianchi-neigong");
        map_skill("dodge", "zhuangzi-wu");
        map_skill("hand", "yunlong-shou");
        map_skill("parry", "sanfen-jianshu");
        map_skill("claw", "yunlong-zhua");
        map_skill("sword", "sanfen-jianshu");

        prepare_skill("hand", "yunlong-shou");
        prepare_skill("claw", "yunlong-zhua");

        create_family("��ɽ��", 16, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "sword.haishi" :),
                (: perform_action, "dodge.hua" :),
                (: exert_function, "recover" :),
        }));

        set("inquiry", ([
                "������¥" : (: ask_skill1 :),
        ]));

        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        setup();
        carry_object(__DIR__"obj/cuiyu")->wear();
        carry_object(__DIR__"obj/huangshan")->wear();
        carry_object(__DIR__"obj/shortsword")->wield();
}

mixed ask_skill1()
{
        object me;

        me = this_player();
        if (me->query("can_perform/sanfen-jianshu/haishi"))
                return "�ף��㲻���Ѿ�������";

        if (!me->query("story/sanfenjian"))
                return "������ʲô��˼��";

        if (me->query_skill("sanfen-jianshu", 1) < 150)
                return "������ֽ����������ң�Ҫ��������";

        message_vision(HIY "$n" HIY "���˵�ͷ���γ�����" NOR +
                       HIC "�̽�" NOR + HIY "��ͻȻȦת��һ"
                       "��֮�����̺����У���ʽ������������"
                       "������\nʵʵ���������ֽ����Ķ���֮��"
                       "������������¥����\n" NOR,
                       me, this_object());
        command("nod");
        command("say ��������ˣ�");
        tell_object(me, HIC "��ѧ���ˡ�������¥����\n" NOR);
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 350000);
        me->set("can_perform/sanfen-jianshu/haishi", 1);
        return 1;
}

int recognize_apprentice(object me, string skill)
{
        if (skill != "muslim")
        {
                command("say ����ʦ��ȥ���������ҡ�");
                return -1;
        }

        if (! me->query_temp("can_learn/huoqingtong"))
        {
                command("sigh");
                command("say �Ҿͽ���һЩ���ģ���������ʱ����"
                        "�졭�����������˰ɡ�");
                me->set_temp("can_learn/huoqingtong", 1);
        }

        return 1;
}

void unconcious()
{
        die();
}

