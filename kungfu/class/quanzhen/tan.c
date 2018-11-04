#include <ansi.h>
#include "quanzhen.h"

inherit NPC;
inherit F_MASTER;

mixed ask_skill1();

void create()
{
        set_name("̷����", ({ "tan chuduan", "tan", "chuduan" }));
        set("long", @LONG
������ȫ���ͽ̷����̷���ˣ�ֻ������Ŀ�
�࣬Ũü���ۣ�ɤ���������ڰݵ���������Ϊ
ʦǰ������������
LONG);
        set("nickname", HIY "������" NOR);
        set("title", "ȫ������");
        set("gender", "����");
        set("age", 40);
        set("class", "taoist");
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 28);
        set("dex", 30);
        set("max_qi", 5200);
        set("max_jing", 4000);
        set("neili", 5600);
        set("max_neili", 5600);
        set("jiali", 200);

        set("combat_exp", 2600000);

        set_skill("force", 240);
        set_skill("quanzhen-xinfa", 240);
        set_skill("xuanmen-neigong", 240);
        set_skill("sword", 240);
        set_skill("qixing-jian", 240);
        set_skill("quanzhen-jian", 240);
        set_skill("dodge", 220);
        set_skill("tianshan-feidu", 220);
        set_skill("jinyan-gong", 220);
        set_skill("parry", 220);
        set_skill("strike", 240);
        set_skill("chongyang-shenzhang", 240);
        set_skill("haotian-zhang", 240);
        set_skill("hand", 240);
        set_skill("qixing-shou", 240);
        set_skill("finger", 240);
        set_skill("zhongnan-zhi", 240);
        set_skill("literate", 240);
        set_skill("taoism", 240);
        set_skill("martial-cognize", 240);

        map_skill("force", "xuanmen-neigong");
        map_skill("sword", "quanzhen-jian");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "quanzhen-jian");
        map_skill("finger", "zhongnan-zhi");
        map_skill("hand", "qixing-shou");
        map_skill("strike", "haotian-zhang");

        prepare_skill("hand", "qixing-shou");
        prepare_skill("strike", "haotian-zhang");

        create_family("ȫ���", 2, "����");

        set("inquiry", ([
                "�����۶�" : (: ask_skill1 :),
        ]) );

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "hand.po" :),
                (: perform_action, "strike.ju" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }));

        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        setup();

        carry_object("/d/quanzhen/npc/obj/grayrobe")->wear();
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query_skill("xuanmen-neigong", 1) < 100
           && (int)ob->query_skill("quanzhen-xinfa", 1) < 100)
        {
                command("say ��ı����ڹ��ķ�����㣬�������Ը�������书��");
                return;
        }

        if ((int)ob->query_skill("taoism", 1) < 100)
        {
                command("say �����������Է��滹���Ӷ����������ѧ�ķ����ߺ������ɡ�");
                return;
        }

        if ((int)ob->query("shen") < 30000)
        {
                command("say �����������������������̫�٣�\n");
                return;
        }

        command("haha");
        command("say ���ã����á�");
        command("recruit " + ob->query("id"));
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/haotian-zhang/ju"))
                return "�����Ҳ����Ѿ��̻�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "������ƶ���ز���ʶ����֪�˻��Ӻ�˵��";

        if (me->query_skill("haotian-zhang", 1) < 1)
                return "��������ƶ�ûѧ����̸���п��ԣ�";

        if (me->query("gongxian") < 250)
                return "������ȫ�����������Ϊ����������ʱ�����ܴ��㡣";

        if (me->query("shen") < 30000)
                return "����������»����ò�������������ʱ�����ܴ��㡣";

        if (me->query_skill("haotian-zhang", 1) < 120)
                return "�������Ʋ�����죬���ߵ������ɡ�";

        if (me->query_skill("force") < 180)
                return "����ڹ���Ϊ�����������ߺ��������Ұɡ�";

        message_sort(HIY "\n$n" HIY "üͷһ�壬���´�����$N" HIY "һ��"
                     "�����¸����𻰣���������һ������Ȼ���һ������ʱ"
                     "˫�Ʒ׷ɣ��ƾ�������˷��ƹ���������ƻֺ�֮����"
                     "\n\n" NOR, me, this_object()); 

        command("say ������ô��");
        tell_object(me, HIC "��ѧ���ˡ������۶�����\n" NOR);
        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("haotian-zhang"))
                me->improve_skill("haotian-zhang", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/haotian-zhang/ju", 1);
        me->add("gongxian", -250);

        return 1;
}
