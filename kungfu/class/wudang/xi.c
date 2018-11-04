#include <ansi.h>
#include "wudang.h"

inherit NPC;
inherit F_MASTER;
inherit F_GUARDER;

mixed ask_me();

void create()
{
        set_name("����Ϫ", ({ "zhang songxi", "zhang", "songxi" }));
        set("nickname", HIC "�䵱����" NOR);
        set("long", "��������������ĵ�������Ϫ����������\n"
                    "ʮ�꣬�����ܸɣ������Ƕ�ı���ơ�\n");
        set("gender", "����");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 26);
        set("int", 33);
        set("con", 26);
        set("dex", 28);
        set("max_qi", 5000);
        set("max_jing", 5000);
        set("neili", 4500);
        set("max_neili", 4500);
        set("jiali", 150);
        set("combat_exp", 1400000);
        set("score", 60000);

        set_skill("force", 220);
        set_skill("wudang-xinfa", 220);
        set_skill("taiji-shengong", 200);
        set_skill("dodge", 220);
        set_skill("tiyunzong", 220);
        set_skill("unarmed", 200);
        set_skill("taiji-quan", 180);
        set_skill("strike", 200);
        set_skill("wudang-zhang", 200);
        set_skill("hand", 200);
        set_skill("paiyun-shou", 200);
        set_skill("parry", 200);
        set_skill("sword", 200);
        set_skill("wudang-jian", 200);
        set_skill("blade", 220);
        set_skill("xuanxu-dao", 220);
        set_skill("taiji-jian", 180);
        set_skill("taoism", 220);
        set_skill("literate", 160);
        set_skill("martial-cognize", 200);

        set("no_teach", ([
                "taiji-shengong" : "Ҫ��ѧϰ̫����������������̡�",
                "taiji-jian"     : "̫���������������״���",
                "taiji-quan"     : "̫��ȭ�����������״���",
        ]));

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "xuanxu-dao");
        map_skill("sword", "wudang-jian");
        map_skill("blade", "xuanxu-dao");
        map_skill("strike", "wudang-zhang");

        prepare_skill("unarmed", "taiji-quan");
        prepare_skill("strike", "wudang-zhang");

        create_family("�䵱��", 2, "����");

        set("inquiry", ([
                "�һ���" : (: ask_me :),
        ]));

        set("coagents", ({
                ([ "startroom" : "/d/wudang/houyuan",
                   "id"        : "yu lianzhou" ]),
                ([ "startroom" : "/d/wudang/sanqingdian",
                   "id"        : "song yuanqiao" ]),
        }));

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "blade.huan" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
		(: exert_function, "shield" :),
        }) );

        setup();
        carry_object("/clone/weapon/blade")->wield();
        carry_object("/d/wudang/obj/whiterobe")->wear();
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("shen") < 8000)
        {
                command("say ���䵱���������������ɣ��Ե���Ҫ���ϡ�");
                command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
                        "�Ƿ����ò�����");
                return;
        }

        if ((int)ob->query_skill("wudang-xinfa", 1) < 60)
        {
                command("say ���䵱����ע���ڹ��ķ�" + RANK_D->query_respect(ob)+
                        "�Ƿ�Ӧ�����䵱�ķ��϶��µ㹦��?");
                return;
        }

        if ((int)ob->query_skill("taoism", 1) < 60)
        {
                command("say ϰ����Ϊ��ǿ���壬һζ�������ǲ���ȡ�ġ�");
                command("say �ҿ��㻹��Ҫ���������Է�����������������"
                        "����ĵ����ķ���");
                return;
        }

        command("say �ðɣ��Ҿ��������ˡ�");
        command("say ϣ�����ܺú��ù�������аħ�����");
        command("recruit " + ob->query("id"));
        if ((string)ob->query("class") != "taoist")
                ob->set("class", "taoist");
}

mixed ask_me()
{
        object me;

        me = this_player();
        if (me->query("can_perform/xuanxu-dao/huan"))
                return "�Ҷ��̸����ˣ��Լ��úö���ϰ�ɣ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "���������䵱�ɵ��ˣ��γ����ԣ�";

        if (me->query_skill("xuanxu-dao", 1) < 1)
                return "�������鵶����ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 150)
                return "��Ϊ���䵱��Ч�����������������Ȳ�æ���㡣";

        if (me->query("shen") < 10000)
                return "������������������Ļ��ܲ������Ҳ��ܴ�����У�";

        if (me->query_skill("xuanxu-dao", 1) < 100)
                return "������鵶���������ң�Ҫ��������";

        message_vision(HIY "$n" HIY "���˵�ͷ�����ֻ������иֵ�������һ"
                       "����Բ\nȦ��ÿ�о����Ի��δ̳��������ջء�������"
                       "������\n��������ֱ����$N" HIY "�ۻ����ҡ�\n" NOR,
                       me, this_object());
        command("smile");
        command("say ������������鵶����Ҫ�裿");
        tell_object(me, HIC "��ѧ���ˡ��һ�������\n" NOR);
        if (me->can_improve_skill("blade"))
                me->improve_skill("blade", 1500000);
        if (me->can_improve_skill("xuanxu-dao"))
                me->improve_skill("xuanxu-dao", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/xuanxu-dao/huan", 1);
        me->add("gongxian", -150);

        return 1;
}
