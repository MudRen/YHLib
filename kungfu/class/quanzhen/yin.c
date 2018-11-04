#include <ansi.h>
#include "quanzhen.h"

inherit NPC;
inherit F_MASTER;

mixed ask_skill1();
mixed ask_skill2();

void create()
{
        set_name("��־ƽ", ({ "yin zhiping", "yin", "zhiping" }));
        set("gender", "����");
        set("age", 24);
        set("class", "taoist");
        set("long", @LONG
�����𴦻��ĵ���������־ƽ������ü���ۣ�
������ЩӢ�����ţ���ȫ��̵�������������
����������Ϊ����Ĳ��ߣ�ü����ƺ���һ��
����֮ɫ�����ĵ��ǳ�ü��Ŀ����ò���ţ���
�����룬��ϧ��ȸ���������в��͡�
LONG);
        set("nickname", HIC "�������" NOR);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 25);
        set("int", 25);
        set("con", 24);
        set("dex", 24);

        set("max_qi", 3000);
        set("max_jing", 2200);
        set("neili", 3500);
        set("max_neili", 3500);
        set("jiali", 100);

        set("combat_exp", 500000);

        set_skill("force", 160);
        set_skill("quanzhen-xinfa", 160);
        set_skill("xuanmen-neigong", 160);
        set_skill("sword", 160);
        set_skill("qixing-jian", 160);
        set_skill("dodge", 140);
        set_skill("tianshan-feidu", 140);
        set_skill("parry", 140);
        set_skill("strike", 140);
        set_skill("chongyang-shenzhang", 140);
        set_skill("finger", 160);
        set_skill("zhongnan-zhi", 160);
        set_skill("literate", 140);
        set_skill("taoism", 140);
        set_skill("martial-cognize", 140);

        map_skill("force", "xuanmen-neigong");
        map_skill("sword", "qixing-jian");
        map_skill("dodge", "tianshan-feidu");
        map_skill("parry", "qixing-jian");
        map_skill("finger", "zhongnan-zhi");
        map_skill("strike", "chongyang-shenzhang");

        prepare_skill("finger", "zhongnan-zhi");
        prepare_skill("strike", "chongyang-shenzhang");

        create_family("ȫ���", 3, "����");

        set("inquiry", ([
                "��ָ��ɽ" : (: ask_skill1 :),
                "Ⱥ����" : (: ask_skill2 :),
        ]) );

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "sword.xing" :),
                (: perform_action, "finger.zhi" :),
                (: perform_action, "strike.lian" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }));

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/quanzhen/npc/obj/grayrobe")->wear();

}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query_skill("xuanmen-neigong", 1) < 30
           && (int)ob->query_skill("quanzhen-xinfa", 1) < 30)
        {
                command("say ����ڹ��ķ�����㣬�ٶ������ɡ�");
                return;
        }

        if ((int)ob->query("shen") < 3000)
        {
                command("say ����������֮������̫�٣��Ҳ������㡣\n");
                return;
        }

        command("say ��Ȼ��ˣ��Ҿ����������ͽ�ܡ�");
        command("recruit " + ob->query("id"));
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/zhongnan-zhi/zhi"))
                return "�����Ҳ����Ѿ��̻�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "������ƶ���ز���ʶ����֪�˻��Ӻ�˵��";

        if (me->query_skill("zhongnan-zhi", 1) < 1)
                return "��������ָ����ûѧ����̸���п��ԣ�";

        if (me->query("gongxian") < 50)
                return "������ȫ�����������Ϊ����������ʱ�����ܴ��㡣";

        if (me->query("shen") < 3000)
                return "����������»����ò�������������ʱ�����ܴ��㡣";

        if (me->query_skill("zhongnan-zhi", 1) < 60)
                return "�������ָ��������죬���ߵ������ɡ�";

        if (me->query_skill("force") < 80)
                return "����ڹ���Ϊ�����������ߺ��������Ұɡ�";

        message_sort(HIY "\n$n" HIY "��$N" HIY "���˵�ͷ�����¸�����"
                     "����΢΢̽��һָ��б�̶�����������ָ��ζ�����"
                     "����ʽ���ᣬ��Ϊ���档\n\n" NOR, me,
                     this_object()); 

        command("nod");
        command("say ���кܼ򵥣��Լ���ϰ��ɡ�");
        tell_object(me, HIC "��ѧ���ˡ���ָ��ɽ����\n" NOR);
        if (me->can_improve_skill("finger"))
                me->improve_skill("finger", 1500000);
        if (me->can_improve_skill("zhongnan-zhi"))
                me->improve_skill("zhongnan-zhi", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/zhongnan-zhi/zhi", 1);
        me->add("gongxian", -50);

        return 1;
}

mixed ask_skill2()
{
        object me;

        me = this_player();

        if (me->query("can_perform/qixing-jian/xing"))
                return "�����Ҳ����Ѿ��̻�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "������ƶ���ز���ʶ����֪�˻��Ӻ�˵��";

        if (me->query_skill("qixing-jian", 1) < 1)
                return "�������ǽ�����ûѧ����̸���п��ԣ�";

        if (me->query("gongxian") < 80)
                return "������ȫ�����������Ϊ����������ʱ�����ܴ��㡣";

        if (me->query("shen") < 3500)
                return "����������»����ò�������������ʱ�����ܴ��㡣";

        if (me->query_skill("qixing-jian", 1) < 60)
                return "������ǽ���������죬���ߵ������ɡ�";

        if (me->query_skill("force") < 80)
                return "����ڹ���Ϊ�����������ߺ��������Ұɡ�";

        message_sort(HIY "\n$n" HIY "΢΢���˵�ͷ����$N" HIY "��������"
                     "˵��Щ����һ��˵��һ�߳�������Ȼ��Ž��С�������"
                     "�ã�$N" HIY "����̧��ͷ���ƺ�����ʲô�µ�����\n"
                     "\n" NOR, me, this_object()); 

        command("nod");
        command("say ���Լ���ȥ��ϰ�ɡ�");
        tell_object(me, HIC "��ѧ���ˡ�Ⱥ���財���\n" NOR);
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("qixing-jian"))
                me->improve_skill("qixing-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/qixing-jian/xing", 1);
        me->add("gongxian", -80);

        return 1;
}
