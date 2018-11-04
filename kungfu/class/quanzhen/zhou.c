#include <ansi.h>
#include "quanzhen.h"

inherit NPC;
inherit F_MASTER;

#define ZHENJING    "/clone/lonely/book/zhenjing1"

mixed ask_skill1();
mixed ask_skill2();

void create()
{
        object ob;
        set_name("�ܲ�ͨ", ({ "zhou botong", "zhou", "botong" }));
        set("gender", "����");
        set("nickname", HIY "����ͯ" NOR);
        set("title", "ȫ��̸���");
        set("long", @LONG
������ȥ��ü�԰ף�һ���õ�ģ����Ȼ������
ȴ͸¶��һ�ɽ��
LONG);
        set("age", 72);
        set("class", "taoist");
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 33);
        set("int", 35);
        set("con", 38);
        set("dex", 33);

        set("max_qi", 47000);
        set("max_jing", 36000);
        set("neili", 20000);
        set("max_neili", 20000);
        set("jingli", 36000);
        set("max_jingli", 36000);
        set("jiali", 450);
        set("combat_exp", 9000000);
        set("score", 900000);

        set_skill("force", 390);
        set_skill("quanzhen-xinfa", 390);
        set_skill("xuanmen-neigong", 390);
        set_skill("xiantian-gong", 390);
        set_skill("yijin-duangu", 390);      // �׽�͹�
        set_skill("unarmed", 390);
        set_skill("dodge", 390);
        set_skill("tianshan-feidu", 390);
        set_skill("jinyan-gong", 390);
        set_skill("shexing-lifan", 390);     // �����귭
        set_skill("parry", 390);
        set_skill("jinguan-yusuo", 390);
        set_skill("unarmed", 390);
        set_skill("kongming-quan", 390);
        set_skill("strike", 390);
        set_skill("chongyang-shenzhang", 390);
        set_skill("haotian-zhang", 390);
        set_skill("finger", 390);
        set_skill("zhongnan-zhi", 390);
        set_skill("hand", 390);
        set_skill("qixing-shou", 390);
        set_skill("sword", 390);
        set_skill("qixing-jian", 390);
        set_skill("quanzhen-jian", 390);
        set_skill("whip", 390);
        set_skill("tiangang-chenfa", 390);
        set_skill("zuoyou-hubo", 400);
        set_skill("taoism", 200);
        set_skill("literate", 100);
        set_skill("martial-cognize", 340);

        map_skill("force", "yijin-duangu");
        map_skill("sword", "quanzhen-jian");
        map_skill("whip", "tiangang-chenfa");
        map_skill("dodge", "shexing-lifan");
        map_skill("parry", "jinguan-yusuo");
        map_skill("unarmed", "kongming-quan");
        map_skill("finger", "zhongnan-zhi");
        map_skill("strike", "haotian-zhang");
        map_skill("hand", "qixing-shou");

        prepare_skill("unarmed", "kongming-quan");

        set("no_teach/xiantian-gong", "�����ҲûŪ������㻹��ȥ����ʦ��ѧ�ɡ�");
        set("no_teach/yijin-duangu",  "�������һ������뷨���ǣ����ܽ��㡣");
        set("no_teach/shexing-lifan", "�������һ������뷨���ǣ����ܽ��㡣");

        create_family("ȫ���", 1, "����");

        set("inquiry", ([
                "ȫ���"   : "��ȫ��������µ����������ڡ�",
                "�����澭" : "����������ʲô��",
                "�λ�ү"   : "�Ρ����λ�ү���˼��ǻ�ү���Ҳ���ʶ��",
                "����"     : "������š��㡭�ղ���˵ɶ���ţ�",
                "����"     : "�š�������š��ţ�",
                "��������" : (: ask_skill1 :),
                "�տ���Ҳ" : (: ask_skill2 :),
        ]));

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: command("perform unarmed.ruo and unarmed.kong") :),
                (: command("perform parry.suo and unarmed.kong") :),
                (: command("perform unarmed.kong twice") :),
                (: perform_action, "dodge.guiyuan" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        set_temp("apply/damage", 200);
        set_temp("apply/unarmed_damage", 200);
        set_temp("apply/armor", 600);

        setup();

        if (clonep())
        {
                ob = find_object(ZHENJING);
                if (! ob) ob = load_object(ZHENJING);

                if (! environment(ob))
                        ob->move(this_object());
        }
                
        carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if (ob->query("combat_exp") < 400000)
        {
                command("say �㾭����ô�����ȥ�����Ǽ���ʦֶ����ɡ�");
                return;
        }

        if ((int)ob->query("shen") < 50000)
        {
                command("say ������Ʒ�в��ã�����һ��϶�������ʲô���¡�");
                return;
        }

        command("smile");
        command("say �������Ҳûɶ�¸ɣ�������������ɡ�");
        command("recruit " + ob->query("id"));
}

int recognize_apprentice(object ob, string skill)
{
        if (! ob->query("can_learn/zuoyou-hubo/zhou"))
        {
                message_vision(CYN "$N" CYN "���˸���������$n" CYN "˵"
                               "�������ֲ�����ʦ����ΪɶҪ���㣿\n" NOR,
                               this_object(), ob);
                return -1;
        }

        if (skill != "zuoyou-hubo")
        {
                command("say ����书���һ��ã�����һ���ࡣ");
                return -1;
        }

        return 1;
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/kongming-quan/ruo"))
                return "�����������������������档";

        if (me->query("family/family_name") != query("family/family_name"))
                return "����˭������ô����ʶ�㣿";

        if (me->query_skill("kongming-quan", 1) < 1)
                return "�ٺ٣������ҵĿ���ȭ��ûѧ������ôѧ���У�";

        if (me->query("gongxian") < 200)
                return "��Ͷ����ȫ��̣�ȴ��Ŭ�����£���ΪʲôҪ���㣿";

        if (me->query("shen") < 50000)
                return "�������ĵػ������ã���ʱ�һ����ܽ��㡣";

        if (me->query_skill("kongming-quan", 1) < 100)
                return "��Ŀ���ȭ�����ò����ã��´���˵�ɡ�";

        if (me->query("max_neili") < 1000)
                return "�����������������治֪��������ô�����ġ�";

        message_sort(HIY "\n$n" HIY "ץ��ץͷ��������Ը���ֹ������䣬��"
                     "��˵������С�ӣ��Ұѿھ�˵��������Ȼ������Լ���ȥ"
                     "���������������ˡ���˵���һ�ѽ�$N" HIY "鱵����"
                     "����$N" HIY "�������󹾹�˵�˰��졣\n\n" NOR, me,
                     this_object()); 

        command("bite");
        command("say ���ˣ����ˣ�����߰ɡ�");
        tell_object(me, HIC "��ѧ���ˡ�������������\n" NOR);
        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", 1500000);
        if (me->can_improve_skill("kongming-quan"))
                me->improve_skill("kongming-quan", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/kongming-quan/ruo", 1);
        me->add("gongxian", -200);

        return 1;
}

mixed ask_skill2()
{
        object me;

        me = this_player();

        if (me->query("can_perform/kongming-quan/kong"))
                return "����������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "����˭������ô����ʶ�㣿";

        if (me->query_skill("kongming-quan", 1) < 1)
                return "�ٺ٣������ҵĿ���ȭ��ûѧ������ôѧ���У�";

        if (me->query("gongxian") < 500)
                return "��Ͷ����ȫ��̣�ȴ��Ŭ�����£���ΪʲôҪ���㣿";

        if (me->query("shen") < 60000)
                return "�������ĵػ������ã���ʱ�һ����ܽ��㡣";

        if (me->query_skill("kongming-quan", 1) < 150)
                return "��Ŀ���ȭ�����ò����ã��´���˵�ɡ�";

        if (me->query("max_neili") < 2000)
                return "�����������������治֪��������ô�����ġ�";

        message_sort(HIY "\n$n" HIY "˫Ŀһ�ɣ���$N" HIY "˵����������ô"
                     "��ô����û�������������𣿡�����$n" HIY "ҡ��ҡͷ��"
                     "�ֵ��������Ǻ�ڵ��������㣬�����ˣ���˵��������һ"
                     "������ƮƮ�ӳ�һȭ��ȭ����ʵ�Ѳ⣬��Χ��ʱ�����ó�"
                     "�����\n\n" NOR, me, this_object()); 

        command("angry");
        command("say ���ߣ����ߣ��Ժ�����������ˡ�");
        tell_object(me, HIC "��ѧ���ˡ��տ���Ҳ����\n" NOR);
        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", 1500000);
        if (me->can_improve_skill("kongming-quan"))
                me->improve_skill("kongming-quan", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/kongming-quan/kong", 1);
        me->add("gongxian", -500);

        return 1;
}

int accept_fight(object ob)
{
        if (is_fighting())
        {
                message_vision(CYN "$N" CYN "��$n" CYN "�е������ȱ�"
                               "���Ҵ�����ܾ��������ġ�\n" NOR,
                               this_object(), ob);
                return -1;
        }

        if (ob->query("combat_exp") < 500000)
        {
                message_vision(CYN "$N" CYN "����һЦ����$n" CYN "����"
                               "�㻹���Ȱѹ�����������˵�ɡ�\n" NOR,
                               this_object(), ob);
                return -1;
        }

        if (query("qi") < 5000 ||
            query("jing") < 3000 ||
            query("neili") < 6000)
        {
                message_vision(CYN "$N" CYN "ҡҡͷ��$n" CYN "��������"
                               "��̫���ˣ�����Ъ�����˵�ɡ�\n" NOR,
                               this_object(), ob);
                return -1;
        }

        if (ob->query("can_learn/zuoyou-hubo/zhou"))
        {
                message_vision(CYN "$N" CYN "��$n" CYN "�����ã�������"
                               "�������档\n" NOR, this_object(), ob);
                return 1;
        }

        message_vision(HIW "$N" HIW "��ϲ�����úúã�����������������"
                       "���Ȼ��Ȼ���\n" NOR, this_object(), ob);

        competition_with(ob);
        return -1;
}

void win()
{
        object ob;
        if (! objectp(ob = query_competitor()))
                return;

        message_vision(CYN "$N" CYN "���˿�$n" CYN "���ٺ�Ц�������ˮ"
                       "ƽ��������������Ҫ�ú��������ú�������\n" NOR,
                       this_object(), ob);
        ::win();
}

void lost()
{
        object ob;
        int exp, pot, sc, ww;
        string msg;

        exp = 20000 + random(10000);
        pot = 2000 + random(1000);
        sc = 800 + random(300);
        ww = 800 + random(300);

        if (! objectp(ob = query_competitor()))
                return;

        message_sort(HIW "\n$N" HIW "��ѽһ����Ĩ��Ĩͷ�ϵĺ���ϲ������"
                     "λ" + RANK_D->query_respect(ob) + HIW "������书"
                     "�������������ɣ��Ұ���Ϊʦ���ˡ�����ҵ㹦������"
                     "����һ�׿�����˫�ִ�ܵ�С��������֮Ϊ���һ�������"
                     "����ȤҲ����ѧѧ���Ժ����������档\n" NOR,
                     this_object(), ob);

        tell_object(ob, HIC "\n�ܲ�ͨͬ�⴫���㡸���һ�������\n" NOR);
        ob->set("can_learn/zuoyou-hubo/zhou", 1);
        ob->improve_skill("martial-cognize", 1500000);

        if (ob->query("potential") > ob->query_potential_limit()) 
        	pot = 1;

        ob->add("combat_exp", exp);
        ob->improve_potential(pot);
        ob->add("score", sc);
        ob->add("weiwang", ww);

        msg = HIC "\nͨ����ε�������������" +
              chinese_number(exp) + "�㾭�顢" +
              chinese_number(pot) + "��Ǳ�ܡ�" +
              chinese_number(sc) + "�㽭��������" +
              chinese_number(ww) + "�㽭��������\n" NOR;

        tell_object(ob, sort_msg(msg));

        ::lost();
}
