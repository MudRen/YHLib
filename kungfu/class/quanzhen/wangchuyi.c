#include <ansi.h>
#include "quanzhen.h"

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;

mixed ask_skill1();
mixed ask_skill2();

void create()
{
        set_name("����һ", ({ "wang chuyi", "wang", "chuyi" }));
        set("long", @LONG
������ȫ������֮�������һ�����ˡ������
�޳��������࣬��縺���Ʈ����ǰ����̬������
LONG);
        set("nickname", RED "������" NOR);
        set("title", "ȫ������");
        set("gender", "����");
        set("age", 41);
        set("class", "taoist");
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 30);
        set("int", 29);
        set("con", 29);
        set("dex", 29);

        set("max_qi", 4200);
        set("max_jing", 3000);
        set("neili", 5000);
        set("max_neili", 5000);
        set("jiali", 150);

        set("combat_exp", 2500000);

        set_skill("force", 240);
        set_skill("quanzhen-xinfa", 240);
        set_skill("xuanmen-neigong", 240);
        set_skill("sword", 240);
        set_skill("qixing-jian", 240);
        set_skill("quanzhen-jian", 240);
        set_skill("dodge", 220);
        set_skill("tianshan-feidu", 220);
        set_skill("parry", 220);
        set_skill("strike", 200);
        set_skill("chongyang-shenzhang", 200);
        set_skill("haotian-zhang", 200);
        set_skill("finger", 200);
        set_skill("zhongnan-zhi", 200);
        set_skill("literate", 220);
        set_skill("taoism", 220);
        set_skill("martial-cognize", 220);

        map_skill("force", "xuanmen-neigong");
        map_skill("sword", "quanzhen-jian");
        map_skill("dodge", "tianshan-feidu");
        map_skill("parry", "quanzhen-jian");
        map_skill("finger", "zhongnan-zhi");
        map_skill("strike", "haotian-zhang");

        prepare_skill("strike", "haotian-zhang");

        create_family("ȫ���", 2, "����");

        set("inquiry", ([
                "���־�" : (: ask_skill1 :),
                "������" : (: ask_skill2 :),
        ]) );

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.ding" :),
                (: perform_action, "strike.ju" :),
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

        if ((int)ob->query_skill("xuanmen-neigong", 1) < 80
           && (int)ob->query_skill("quanzhen-xinfa", 1) < 80)
        {
                command("say ��ı����ڹ��ķ�����㣬�������Ը�������书��");
                return;
        }

        if ((int)ob->query_skill("taoism", 1) < 80)
        {
                command("say �����������Է��滹���Ӷ����������ѧ�ķ����ߺ������ɡ�");
                return;
        }

        if ((int)ob->query("shen") < 10000)
        {
                command("say �����������������������̫�٣�\n");
                return;
        }

        command("nod");
        command("say �ðɣ��Ҿ��������ˡ�");
        command("recruit " + ob->query("id"));
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/quanzhen-jian/chan"))
                return "�����Ҳ����Ѿ��̻�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "������ƶ���ز���ʶ����֪�˻��Ӻ�˵��";

        if (me->query_skill("quanzhen-jian", 1) < 1)
                return "����ȫ�潣����ûѧ����̸���п��ԣ�";

        if (me->query("gongxian") < 200)
                return "������ȫ�����������Ϊ����������ʱ�����ܴ��㡣";

        if (me->query("shen") < 10000)
                return "����������»����ò�������������ʱ�����ܴ��㡣";

        if (me->query_skill("quanzhen-jian", 1) < 80)
                return "���ȫ�潣��������죬���ߵ������ɡ�";

        if (me->query_skill("force") < 100)
                return "����ڹ���Ϊ�����������ߺ��������Ұɡ�";

        message_sort(HIY "\n$n" HIY "΢Ц�ŵ��˵�ͷ��˵�����������ˡ���˵"
                     "�ռ�������䳤����������ʾ������ֻ��$n" HIY "���н�"
                     "��Բ�������಻������������ϸ˿��ӳ�������͸��������"
                     "���������ֱ����$N" HIY "Ŀ�ɿڴ���\n\n" NOR, me,
                     this_object()); 

        command("nod");
        command("say �����޷����Խ����Ի���֣����޸���֮�١�");
        tell_object(me, HIC "��ѧ���ˡ����־�����\n" NOR);
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("quanzhen-jian"))
                me->improve_skill("quanzhen-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/quanzhen-jian/chan", 1);
        me->add("gongxian", -200);

        return 1;
}

mixed ask_skill2()
{
        object me;

        me = this_player();

        if (me->query("can_perform/quanzhen-jian/ding"))
                return "�����Ҳ����Ѿ��̻�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "������ƶ���ز���ʶ����֪�˻��Ӻ�˵��";

        if (me->query_skill("quanzhen-jian", 1) < 1)
                return "����ȫ�潣����ûѧ����̸���п��ԣ�";

        if (me->query("gongxian") < 400)
                return "������ȫ�����������Ϊ����������ʱ�����ܴ��㡣";

        if (me->query("shen") < 12000)
                return "����������»����ò�������������ʱ�����ܴ��㡣";

        if (me->query_skill("quanzhen-jian", 1) < 100)
                return "���ȫ�潣��������죬���ߵ������ɡ�";

        if (me->query_skill("force") < 150)
                return "����ڹ���Ϊ�����������ߺ��������Ұɡ�";

        message_sort(HIY "\n$n" HIY "���˵�ͷ���ȵ���������ϸ�ˡ���������"
                     "�䣬ֻ��$n" HIY "�������Ҽ�����������һ����������"
                     "��������������������ʯ��һ��бб�̳�����ʱֻ���á�"
                     "�ꡱ��һ����$N" HIY "���µķ�ש��ȻӦ�����飬�ѳ���"
                     "���顣\n\n" NOR, me, this_object()); 

        command("nod");
        command("say ���еľ�Ҫ�޷��������ݽ�����������������");
        tell_object(me, HIC "��ѧ���ˡ������롹��\n" NOR);
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("quanzhen-jian"))
                me->improve_skill("quanzhen-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/quanzhen-jian/ding", 1);
        me->add("gongxian", -400);

        return 1;
}
