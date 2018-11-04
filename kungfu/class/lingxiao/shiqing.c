#include <ansi.h>;

#define MOJIAN    "/clone/lonely/mojian"

inherit NPC;

mixed ask_jian();
mixed ask_skill1();
mixed ask_skill2();

void create()
{
        object ob;
        set_name("ʯ��", ({ "shi qing", "shi", "qing"}));
        set("gender", "����");
        set("title", "��������ׯׯ��");
        set("nickname", HIW "����˫��" NOR);
        set("age", 37);
        set("long", @LONG
����ǽ�������ׯׯ��ʯ�壬���ڽ���������
���ã�Ϊ�˺������塣ֻ���������ʣ�����
ƮƮ���������һ��������
LONG );
        set("attitude", "peaceful");
        set("shen_type", 1); 
        set("str", 32);
        set("int", 31);
        set("con", 33);
        set("dex", 31);

        set("max_qi", 4500);
        set("max_jing", 3000);
        set("neili", 5000);
        set("max_neili", 5000);
        set("jiali", 180);
        set("combat_exp", 2200000);
        set("score", 25000); 

        set_skill("force", 220);
        set_skill("wuwang-shengong", 220);
        set_skill("sword", 220);
        set_skill("shangqing-jian", 220);
        set_skill("dodge", 220);
        set_skill("feiyan-zoubi", 220);
        set_skill("strike", 220);
        set_skill("piaoxu-zhang", 220);
        set_skill("parry", 220);
        set_skill("literate", 250);
        set_skill("martial-cognize", 180);

        map_skill("force", "wuwang-shengong");
        map_skill("sword", "shangqing-jian");
        map_skill("dodge", "feiyan-zoubi");
        map_skill("parry", "shangqing-jian");
        map_skill("strike", "piaoxu-zhang");

        prepare_skill("strike", "piaoxu-zhang");

        set("inquiry", ([
                "ī��"   : (: ask_jian :),
                "������" : (: ask_skill1 :),
                "������" : (: ask_skill2 :),
                "����"   : "�������µ����ӣ�������������",
                "������" : "�ҿ�Ƿ��ʵ��̫�࣬ʵ��̫�ࡣ",
                "������" : "�������������������������ںų������书��һ������������˫��",
                "����" : "��������������������֮�ӣ��ųơ����������������������˵á�",
                "ʯ����" : "�������µ�Ȯ�ӣ����Ӳ��ϣ��Һ޲�������ɱ������",
                "������" : "����������д�������뵽л�̿�Ϊ���������¡�",
                "л�̿�" : "л�̿ͱ��ǡ�Ħ���ʿ�����������ɢ����������ö��",
        ]));

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "sword.zhuo" :),
                (: perform_action, "sword.qing" :),
                (: exert_function, "recover" :),
        }) );

        setup();

        if (clonep())
        {
                ob = find_object(MOJIAN);
                if (! ob) ob = load_object(MOJIAN);
                if (! environment(ob))
                {
                        ob->move(this_object());
                        ob->wield();
                } else
                {
                        ob = new("/clone/weapon/changjian");
                        ob->move(this_object());
                        ob->wield();
                }
        }

        carry_object("/d/city/npc/cloth/cloth")->wear();
        add_money("silver", 50);
}

int recognize_apprentice(object ob, string skill)
{
        if (interactive(ob) && (! ob->query("family") ||
           ob->query("family")["master_name"] != "������"))
        {
                command("hmm");
                command("say ʯĳ���������ԨԴ����̸���ڶ��֣�\n");
                return -1; 

        }

        if ((int)ob->query("shen") < 10000)
        {
                command("heng");
                command("say ��ʯĳ���ܽ���ʦ�Ľ������������ֽ�����С��");
                return -1;
        }

        if (skill != "shangqing-jian" && skill != "sword")
        {
                command("shake");
                command("say ��ֻ�������彣����һЩ�����Ľ���֪ʶ������ȥ����"
                        "ʦ��ѧ�ɡ�");
                return -1;
        }

        if (skill == "sword" && ob->query_skill("sword", 1) > 179)
        {
                command("hmm");
                command("say ��Ľ��������Ѿ���ͬ�����ˣ�ʣ�¾��Լ�ȥ���ɡ�");
                return -1;
        }

        if (! ob->query_temp("can_learn/shiqing"))
        {
                command("sigh");
                command("say �������ҿ�Ƿ��ѩɽ��ʵ��̫�࣬���������׽���Ҳ��"
                        "Ӧ�õġ�");
                ob->set_temp("can_learn/shiqing", 1);
        }
        return 1;
}

mixed ask_skill1()
{
        object me;

        me = this_player();
        if (me->query("can_perform/shangqing-jian/zhuo"))
                return "���и��²����Ѿ���������";

        if (me->query("family/family_name") != "������")
                return "ʯĳ���������ԨԴ����֪�����⻰�Ӻζ�����";

        if (me->query_skill("shangqing-jian", 1) < 1)
                return "�������彣����ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 800)
                return "�ţ�����ѩɽ���еĵ�λ�����������Ҵ�����һ�С�";

        if (me->query("shen") < 15000)
                return "ѧ��֮�ˣ���Ӧ�Ե���Ϊ�ȡ��������������ò����������Ҳ��ܴ��㡣";

        if (me->query_skill("force") < 200)
                return "����ڹ�����̫ǳ���ò�����һ�У�";

        if (me->query_skill("shangqing-jian", 1) < 140)
                return "�����彣����δ�����þ��û�������С�";

        message_vision(HIY "$n" HIY "΢΢һЦ���ӻ�������ȡ����һ��"
                       "���ף�ָ������һ�ζ�$N" HIY "ϸ\n˵���ã�$N"
                       HIY "һ����һ�ߵ�ͷ��\n" NOR, me, this_object());

        command("nod");
        command("say �ղ�����˵��ȫ�����еľ������ڣ�����ȥ�������ɡ�");
        tell_object(me, HIC "��ѧ���ˡ�����������\n" NOR);

        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("shangqing-jian"))
                me->improve_skill("shangqing-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/shangqing-jian/zhuo", 1);
        me->add("gongxian", -800);
        return 1;
}

mixed ask_skill2()
{
        object me;

        me = this_player();
        if (me->query("can_perform/shangqing-jian/qing"))
                return "���и��²����Ѿ���������";

        if (me->query("family/family_name") != "������")
                return "ʯĳ���������ԨԴ����֪�����⻰�Ӻζ�����";

        if (me->query_skill("shangqing-jian", 1) < 1)
                return "�������彣����ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 1600)
                return "�ţ�����ѩɽ���еĵ�λ�����������Ҵ�����һ�С�";

        if (me->query("shen") < 30000)
                return "ѧ��֮�ˣ���Ӧ�Ե���Ϊ�ȡ��������������ò����������Ҳ��ܴ��㡣";

        if (! me->query("can_perform/shangqing-jian/zhuo"))
                return "��������������ͨ����������������ѧ���аɡ�";

        if (me->query_skill("force") < 220)
                return "����ڹ�����̫ǳ���ò�����һ�У�";

        if (me->query_skill("shangqing-jian", 1) < 160)
                return "�����彣����δ�����þ��û�������С�";

        message_vision( HIY "$n" HIY "����һЦ����$N" HIY "Ц������û��"
                        "��������ѩɽ�ɣ�ȴ���������\n�Ľ���������˳�"
                        "���뻯��ʯĳ���ձ㴫�����к��ˡ���ֻ��$n" HIY
                        "\n˵�꣬�㿪ʼ��������ʾ���У���˷��������顣"
                        "$N" HIY "��һ����ϸ��\n����������һЦ���ƺ�"
                        "������ʲô��\n" NOR, me, this_object());
        command("nod");
        command("say �ղ�����ʾ����ͼ������𣿼����˾��Լ���ȥ���ɡ�");
        tell_object(me, HIC "��ѧ���ˡ�����������\n" NOR);

        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("shangqing-jian"))
                me->improve_skill("shangqing-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/shangqing-jian/qing", 1);
        me->add("gongxian", -1600);
        return 1;
}

mixed ask_jian()
{
        object me;
        object ob;
        object owner;

        me = this_player();
        if (me->is_bad())
        {
                if (me->query("family/family_name") == "������")
                        message_vision(CYN "$N" CYN "���һ������$n" CYN "����"
                                       "�������ٸ�������ǰ˵�����ģ�С������ѩ"
                                       "ɽ�������������࣡��\n" NOR,
                                       this_object(), me);
                else
                        message_vision(CYN "$N" CYN "��Цһ������$n" CYN "˵��"
                                       "��������ʲô��ͷ����Ȼ�Ҵ���ʯĳ���佣"
                                       "����\n" NOR,
                                       this_object(), me);
                return 1;
        }

        if (me->query("family/family_name") != "������")
                return "ʯĳ������ز���ʶ����֪�����޹ʴ������µ��佣����Ϊ�Σ�";

        if (me->query("family/master_id") != "bai zizai")
                return "�ߣ���ƾ��Ҳ��Ҫʯĳ���佣��Ҫ������ʦ�����ɣ�";

        if (me->query("shen") < 30000)
                return "ѧ��֮�ˣ���Ӧ�Ե���Ϊ�ȡ��ҵ��佣���������ˣ����߰ɡ�";

        if (me->query_skill("shangqing-jian", 1) < 150)
                return "ī��ֻ�����������۵Ľ���������ʾ���������㽣�����ú������ɡ�";

        ob = find_object(MOJIAN);
        if (! ob) ob = load_object(MOJIAN);
        owner = environment(ob);
        while (owner)
        {
                if (owner->is_character() || ! environment(owner))
                        break;
                owner = environment(owner);
        }

        if (owner == me)
                return "�ţ�ʯĳ��ī����������������";

        if (objectp(owner) && owner != this_object())
        {
                if (! owner->is_character())
                        return "��������һ�����ҵ��佣�Ѿ��ñ���ȡȥ�ˡ�";

                if (owner->query("family/family_name") == "������")
                        return "�ҵ��佣����ѩɽ�ɵ�" + owner->query("name") +
                               "ȡȥ�ˣ���Ҫ�þ�ȥ�����ɡ�";
                else
                        return "�ҵ��佣��" + owner->query("name") +
                               "ȡȥ�ˣ���ȥ�����ɣ�";
        }
        ob->move(this_object());

        ob = new("/clone/weapon/changjian");
        ob->move(this_object());
        ob->wield();

        message_vision(CYN "$N" CYN "̾�������ҵ��佣����ȥ�ðɣ���"
                       "�м����߽�����һ��һ����Ϊ�أ���\n" NOR,
                       this_object(), me);
        command("give mo jian to " + me->query("id"));
        return 1;
}
