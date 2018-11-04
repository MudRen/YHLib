// ouyangfeng.c

#include <ansi.h>
#include "ouyang.h"

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;
inherit F_QUESTER;

mixed ask_me();
mixed ask_music_book();

void create()
{
        set_name("ŷ����", ({ "ouyang feng", "ouyang", "feng" }));
        set("long", "�����ǰ���ɽׯ�����ųơ���������ŷ���档����������\n"
                    "�����⺷����Ȼ�ܵ�������ƭ��ѧϰ�ˡ������澭������\n"
                    "����ħ��һ�ȱ�þ�����ң�����������Ȼ�ָ���������\n"
                    "ʤ������\n");
        set("title", "�������ɽׯ��");
        set("gender", "����");
        set("age", 53);
        set("nickname", HIR "����" NOR);
        set("shen_type", -1);
        set("attitude", "peaceful");

        set("str", 32);
        set("int", 34);
        set("con", 34);
        set("dex", 32);

        set("qi", 6000);
        set("max_qi", 6000);
        set("jing", 5000);
        set("max_jing", 5000);
        set("neili", 8000);
        set("max_neili", 8000);
        set("jiali", 200);

        set("combat_exp", 4000000);

        set_skill("force", 340);
        set_skill("unarmed", 340);
        set_skill("dodge", 340);
        set_skill("parry", 340);
        set_skill("cuff", 340);
        set_skill("finger", 340);
        set_skill("staff", 340);
        set_skill("training", 340);
        set_skill("poison", 340);
        set_skill("shedu-qiqiao", 340);
        set_skill("hamagong", 340);
        set_skill("chanchu-bufa", 340);
        set_skill("lingshe-quan", 340);
        set_skill("lingshe-zhangfa", 340);
        set_skill("baibian-daxue", 340);
        set_skill("guzheng-jifa", 320);
        set_skill("xiyu-tiezheng", 320);
        set_skill("wushe-qu", 320);
        set_skill("literate", 280);
        set_skill("medical", 360);
        set_skill("baituo-michuan", 360);
        set_skill("martial-cognize", 320);

        map_skill("force", "hamagong");
        map_skill("dodge", "chanchu-bufa");
        map_skill("cuff", "lingshe-quan");
        map_skill("parry", "lingshe-zhangfa");
        map_skill("staff", "lingshe-zhangfa");
        map_skill("finger", "shedu-qiqiao");
        map_skill("poison", "shedu-qiqiao");
        map_skill("medical", "baituo-michuan");
        map_skill("guzheng-jifa", "xiyu-tiezheng");

        prepare_skill("finger", "shedu-qiqiao");
        prepare_skill("cuff", "lingshe-quan");

        create_family("ŷ������", 5, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "staff.chan" :),
                (: perform_action, "staff.qianshe" :),
                (: perform_action, "staff.wuji" :),
                (: perform_action, "cuff.rou" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }));

        set("inquiry", ([
                "����"     : (: ask_me :),
                "����"     : (: ask_me :),
                "ǧ�߳���" : (: ask_me :),
                "����"     : (: ask_music_book :),
                "���ݼ���" : (: ask_music_book :),
        ]));

        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        set("music_book", 1);

        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("d/baituo/obj/tiezheng");
        add_money("silver", 50);
}

int recognize_apprentice(object me, string skill)
{
        if (skill != "guzheng-jifa")
                return 0;

        if (me->query_temp("can_learn/ouyang/guzheng-jifa"))
                return 1;

        command("say �ðɣ���Ը��ѧ�Ҿʹ���һ�����֮����");
        me->set_temp("can_learn/ouyang/guzheng-jifa", 1);
        return 1;
}

void attempt_apprentice(object ob)
{
        if(! permit_recruit(ob))
                return;

        if((int)ob->query("combat_exp") < 200000)
        {
                if (random(2))
                        command("smile");
                else
                        command("pat " + ob->query("id"));

                command("say ��ľ��黹�������Ⱥ��ҵ�ֶ��ŷ����ѧϰ�书�ɡ�");
                return ;
        }

        command("sigh");
        command("pat " + ob->query("id"));
        command("recruit " + ob->query("id"));
        command("say ����������ŷ�����Ǻ�����ˡ�");
        return;
}

mixed ask_me()
{
        object me;

        me = this_player();
        if (me->query("can_perform/lingshe-zhangfa/qianshe"))
                return "�㻹����ȥ����ȥ���úð�����ŷ���ҷ�����";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�����Ķ����ģ�����ô��";

        if (me->query("shen") > -40000)
                return "�������ֶβ����ݶ��������ڻ����ܴ�����У�";

        if (me->query_skill("lingshe-zhangfa", 1) < 120)
                return "���Ⱥúð������ȷ���������˵��";

        message_vision(HIY "$n" HIY "�ȵ�������ϸ�ˣ�˵�ѵ�"
                       "�ۺ�ɨ�����������������Ǳ�������$N"
                       HIY "���۾�����ֱ�ˡ�\n" NOR,
                       me, this_object());
        command("heihei");
        command("say ����ʾ����ô������㿴����û�У�");
        tell_object(me, HIG "��ѧ����ǧ�߳�����\n" NOR);
        if (me->can_improve_skill("staff"))
                me->improve_skill("staff", 90000);
        me->set("can_perform/lingshe-zhangfa/qianshe", 1);
        return 1;
}

mixed ask_music_book()
{
        object me;
        object ob;

        me = this_player();
        if (query("music_book") < 1)
                return "�ҵ������Ѿ����ȥ�ˡ�\n";

        ob = new("/clone/book/zhengpu");
        ob->move(me, 1);
        message_vision("$n�����׸���$N����������ȥ�Լ��ú���ĥ�ɡ�\n",
                       me, this_object());
        set("music_book", 0);
        return 1;
}

void reset()
{
        set("music_book", 1);
}

void unconcious()
{
        die();
}
