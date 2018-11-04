#include <ansi.h>;
inherit NPC;

#define ZHENJING    "/clone/lonely/book/zhenjing2"

void create()
{
        object ob;
        set_name("������", ({ "chen xuanfeng", "chen", "xuanfeng" }));
        set("title", "�ڷ�˫ɷ");
        set("nickname", YEL "ͭʬ" NOR);
        set("gender", "����");
        set("age", 35);
        set("long", "�����ǻ�ҩʦ�Ķ����ӣ���Ũü���ۣ�������������\n"
                    "��׳����ֻ����ɫ΢΢���ơ�\n");
        set("attitude", "aggressive");
        set("str", 28);
        set("int", 25);
        set("con", 30);
        set("dex", 25);
        set("shen_type", -1);

        set("max_qi", 35000);
        set("max_jing", 23500);
        set("neili", 16000);
        set("max_neili", 16000);
        set("jiali", 420);

        set("combat_exp", 2000000);

        set_skill("claw", 340);
        set_skill("strike", 340);
        set_skill("force", 320);
        set_skill("parry", 340);
        set_skill("dodge", 320);
        set_skill("cuixin-zhang", 340);
        set_skill("jiuyin-baiguzhao", 340);
        set_skill("luoying-xinfa", 320);
        set_skill("anying-fuxiang", 320);
        set_skill("martial-cognize", 320);

        map_skill("force", "luoying-xinfa");
        map_skill("parry", "jiuyin-baiguzhao");
        map_skill("dodge", "anying-fuxiang");
        map_skill("claw", "jiuyin-baiguzhao");
        map_skill("strike", "cuixin-zhang");

        prepare_skill("claw", "jiuyin-baiguzhao");
        prepare_skill("strike", "cuixin-zhang");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "claw.duo" :),
                (: perform_action, "claw.zhua" :),
                (: perform_action, "strike.cui" :),
                (: exert_function, "recover" :),
        }));

        create_family("�һ���", 2, "�������");
        set("inquiry", ([
                "ͭʬ" : "�����ϵ��˶���ô���ҵģ����²��£�����������",
                "��а" : "������ʦ���Ĵºš�",
                "����" : "�������ʦ�����ĸ���֮һ���Ǹ��϶��ס�ڰ���ɽ��",
                "�ϵ�" : "����ү�ѳ��ҵ�����ȥ�ˣ�������һ�ơ�",
                "��ؤ" : "��ؤͳ����ԭ��ؤ�������Ϊǿ��",
                "����" : "������ʦ���Ķ�Ů�����ǵ������ԡ�",
                "���߹�" : "���߹��书��ǿ�����ҽ̻������С������ʮ���ƣ��ɺޣ�",
                "÷����" : "�����ҵ�ʦ�ã�Ҳ���ҵ����ҡ�",
                "������" : "��������ô�����ǰ׳հ���",
                "��ҩʦ" : "������ʦ����"
	]));
        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        setup();

        if (clonep())
        {
                ob = find_object(ZHENJING);
                if (! ob) ob = load_object(ZHENJING);

                if (! environment(ob))
                        ob->move(this_object());
        }
        carry_object("/clone/cloth/bupao")->wear();
}

void attempt_apprentice(object ob)
{
        command("say �ٷ��ң������");
}

int accept_fight(object me)
{
        command("say ���ҹ�����");
        return 0;
}

int accept_hit(object me)
{
        command("say ������");
        kill_ob(me);
        return 1;
}

void kill_ob (object ob)
{
        object me = this_object();
        object where = environment(me);
        object guard = present("mei chaofeng", where);

        set_temp("my_killer", ob);
        ::kill_ob(ob);

        if (guard && ! guard->is_fighting())
        {
                message_vision(HIW "\n$N" HIW "��ŭ������Ȼ�۸������Ǻڷ�˫ɷ"
                               "ͷ�����ˣ����ɣ�\n\n" NOR, guard);
                guard->kill_ob(ob);
        }
}
