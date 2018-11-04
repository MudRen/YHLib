#include <ansi.h>
#include "xuedao.h"

#define XUEDAO    "/clone/lonely/xuedao"
#define JING      "/clone/lonely/book/xuedao"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;
inherit F_COAGENT;

mixed ask_skill1();
mixed ask_skill2();
mixed ask_skill3();
mixed ask_skill4();
mixed ask_skill5();
mixed ask_skill6();
mixed ask_skill7();
mixed ask_skill8();
mixed ask_skill9();

mixed ask_dao();
mixed ask_book();
mixed ask_midao();

void create()
{
        object ob;
        set_name("Ѫ������", ({ "xuedao laozu", "xuedao", "laozu", "xue", "lao" }));
        set("long", @LONG
���������Ż��ۣ���ͼ��ϣ���ͷ���������϶���
���ơ�������Ѫ���ŵ��Ĵ����š�
LONG);
        set("gender", "����");
        set("age", 85);
        set("attitude", "peaceful");
        set("shen_type", -1);

        set("str", 33);
        set("int", 31);
        set("con", 35);
        set("dex", 32);
        set("max_qi", 5500);
        set("max_jing", 4000);
        set("neili", 5800);
        set("max_neili", 5800);
        set("jiali", 200);
        set("combat_exp", 3500000);

        set_skill("force", 280);
        set_skill("xuedao-dafa", 280);
        set_skill("mizong-neigong", 260);
        set_skill("blade", 280);
        set_skill("xueshan-dao", 260);
        set_skill("honglian-dao", 260);
        set_skill("sword", 240);
        set_skill("mingwang-jian", 240);
        set_skill("dodge", 260);
        set_skill("shenkong-xing", 260);
        set_skill("hand", 260);
        set_skill("dashou-yin", 260);
        set_skill("cuff", 260);
        set_skill("yujiamu-quan", 260);
        set_skill("parry", 260);
        set_skill("lamaism", 240);
        set_skill("literate", 200);
        set_skill("martial-cognize", 260);

        map_skill("force", "xuedao-dafa");
        map_skill("dodge", "shenkong-xing");
        map_skill("hand", "dashou-yin");
        map_skill("cuff", "yujiamu-quan");
        map_skill("parry", "xuedao-dafa");
        map_skill("blade", "xuedao-dafa");
        map_skill("sword", "mingwang-jian");

        prepare_skill("cuff", "yujiamu-quan");
        prepare_skill("hand", "dashou-yin");

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "blade.ying" :),
                (: perform_action, "blade.chi" :),
                (: perform_action, "blade.xue" :),
                (: perform_action, "blade.shi" :),
                (: perform_action, "hand.yin" :),
                (: perform_action, "cuff.jiang" :),
                (: exert_function, "recover" :),
                (: exert_function, "resurrect" :),
                (: exert_function, "powerup" :),

        }) );

        create_family("Ѫ����", 4, "����");
        set("class", "bonze");

        set("inquiry", ([
                "Ѫ��"      : (: ask_dao :),
                "Ѫ����"    : (: ask_book :),
                "�ܵ�"      : (: ask_midao :),
                "�ص�"      : (: ask_midao :),
                "ԡѪ����"  : (: ask_skill1 :),
                "���ӡ"    : (: ask_skill2 :),
                "���޽���"  : (: ask_skill3 :),
                "����"      : (: ask_skill4 :),
                "��ħ"      : (: ask_skill5 :),
                "��Ӱ��"  : (: ask_skill6 :),
                "������"  : (: ask_skill7 :),
                "��Ѫ��"  : (: ask_skill8 :),
                "��Ѫ��"  : (: ask_skill9 :),
                "���ӿ���"  : "��һ����ȥ��ʤ�н�����ˡ�",
                "���ǻ���"  : "��һ����ȥ�ñ��������ˡ�",
                "Ѫ���ޱ�"  : "�٣���������ȥ�������ӿڣ��������Ҹ��",
        ]));

        setup();

        set_temp("apply/damage", 100); 
        set_temp("apply/unarmed_damage", 100); 
        set_temp("apply/armor", 200); 

        if (clonep())
        {
                ob = find_object(XUEDAO);
                if (! ob) ob = load_object(XUEDAO);
                if (! environment(ob))
                {
                        ob->move(this_object());
                        ob->wield();
                } else
                {
                        ob = new("clone/weapon/jiedao");
                        ob->move(this_object());
                        ob->wield();
                }
        }

        carry_object("/d/xueshan/obj/y-jiasha")->wear();
        add_money("silver", 20);
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((string)ob->query("gender") == "Ů��")
        {
                command("say �Ϸ���Ůͽ�ܣ����������������档\n");
                return;
        }

        if ((string)ob->query("gender") != "����")
        {
                command("say ��ƽ������ߵľ������ˣ��ٲ�������ɱ���㣡\n");
                return;
        }

        if (ob->query("class") != "bonze")
        {
                ob->set_temp("pending/join_bonze", 1);
                command("say �㲻�ǳ����ˣ�����Ѫ�����ǲ��������ġ�"
                        "�����Ҫ���ң�ȥ�����¡�");
                return;
        }

        if ((int)ob->query("combat_exp") < 350000)
        {
                command("say ���ʵս����Ҳ߯���ˣ���ȥ�úø�������ȥ��");
                return;
        }

        if ((int)ob->query("shen") > -50000)
        {
                command("say ���ǲ����������������ɱ�˶����ᣡ\n");
                return;
        }

        if ((int)ob->query_skill("lamaism", 1) < 140)
        {
                command("say ��˵զ��ƽʱ��ɱ���ӣ����ܹ�Ҳ���Ƿ��ŵ��ӡ�\n");
                command("say ��������ڷ���ߺ��������Ұɡ�\n");
                return;
        }

        if ((int)ob->query_skill("mizong-neigong", 1) < 100)
        {
                command("say ����������ô���ģ��ڹ���ô�\n");
                return;
        }

        if ((int)ob->query_skill("blade", 1) < 120)
        {
                command("say �㵶����ô������������ң�\n");
                return;
        }

        command("sneer");
        command("say �����Ժ�͸����Ϸ���ˡ�");
        command("recruit " + ob->query("id"));
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/xuedao-dafa/resurrect"))
                return "�Լ���ȥ��������ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "����ʲô�ˣ��ҿ�����ô��������Ѫ���ŵĵ����أ�";

        if (me->query_skill("xuedao-dafa", 1) < 1)
                return "����Ѫ���󷨶�ûѧ��������ʲô��";

        if (me->query("gongxian") < 500)
                return "����Ϸ�������£��Ϸ���Ȼ�ᴫ�������";

        if (me->query("shen") > -60000)
                return "����������ô���ģ���ɱ�˶������ˣ�";

        if (me->query("max_neili") < 1000)
                return "������������������Ȼ������˼�����Ϸ�";

        if (me->query_skill("xuedao-dafa", 1) < 120)
                return "�����Ѫ�����������������Ϸ�";

        message_vision(HIY "$n" HIY "΢΢һЦ������Ҳ���𻰣�ֻ��������֣������"
                       "��\n$N" HIY "�ؿڡ�����$N" HIY "�ɻ�䣬ȴ��$n" HIY "�ƾ�"
                       "���£�$N" HIY "��ʱȫ��\nһ�������������������޲��泩"
                       "��˵���������á�\n" NOR, me, this_object());

        command("sneer");
        command("say ������ô��");
        tell_object(me, HIC "��ѧ���ˡ�ԡѪ��������\n" NOR);

        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("xuedao-dafa"))
                me->improve_skill("xuedao-dafa", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/xuedao-dafa/resurrect", 1);
        me->add("gongxian", -500);

        return 1;
}

mixed ask_skill2()
{
        object me;

        me = this_player();

        if (me->query("can_perform/dashou-yin/yin"))
                return "�Լ���ȥ��������ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "����ʲô�ˣ��ҿ�����ô��������Ѫ���ŵĵ����أ�";

        if (me->query_skill("dashou-yin", 1) < 1)
                return "��������ӡ��ûѧ��������ʲô��";

        if (me->query("gongxian") < 200)
                return "����Ϸ�������£��Ϸ���Ȼ�ᴫ�������";

        if (me->query("shen") > -15000)
                return "����������ô���ģ���ɱ�˶������ˣ�";

        if (me->query_skill("force") < 140)
                return "����ڹ���Ϊʵ��̫����������������Ϸ�ɡ�";

        if (me->query("max_neili") < 1000)
                return "������������������Ȼ������˼�����Ϸ�";

        if (me->query_skill("dashou-yin", 1) < 100)
                return "����Ѵ���ӡ�������������Ϸ�";

        message_vision(HIY "$n" HIY "��Цһ�������´�����$N" HIY "һ�������˵�ͷ"
                       "����������\n���ģ�����ׯ�أ�˫��Я�ž��������$N" HIY "��ǰ"
                       "��һ����������\n���䣬��ʱֻ����Ȼһ�����죬�����ڵ����"
                       "��$n" HIY "����\n���������Ĵ������������������������ɢ"
                       "��$N" HIY "��ŷ���\n�������������ϻ�ȻǶ��һ˫��ӡ��\n"
                       NOR, me, this_object());

        command("nod");
        command("say ֻҪ�ڹ����������в���������");
        tell_object(me, HIC "��ѧ���ˡ����ӡ����\n" NOR);

        if (me->can_improve_skill("hand"))
                me->improve_skill("hand", 1500000);
        if (me->can_improve_skill("dashou-yin"))
                me->improve_skill("dashou-yin", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/dashou-yin/yin", 1);
        me->add("gongxian", -200);

        return 1;
}

mixed ask_skill3()
{
        object me;

        me = this_player();

        if (me->query("can_perform/yujiamu-quan/jiang"))
                return "�Լ���ȥ��������ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "����ʲô�ˣ��ҿ�����ô��������Ѫ���ŵĵ����أ�";

        if (me->query_skill("yujiamu-quan", 1) < 1)
                return "����������ĸȭ��ûѧ��������ʲô��";

        if (me->query("gongxian") < 300)
                return "����Ϸ�������£��Ϸ���Ȼ�ᴫ�������";

        if (me->query("shen") > -18000)
                return "����������ô���ģ���ɱ�˶������ˣ�";

        if (me->query_skill("force") < 150)
                return "����ڹ���Ϊʵ��̫����������������Ϸ�ɡ�";

        if (me->query("max_neili") < 1200)
                return "������������������Ȼ������˼�����Ϸ�";

        if (me->query_skill("yujiamu-quan", 1) < 100)
                return "����ѽ�����ĸȭ�������������Ϸ�";

        message_vision(HIY "$n" HIY "��΢���˵�ͷ���������һ�������ݲ���ǰ����Ŀ"
                       "��\n�ȣ�ȭ�е��������籼�ף���ʱ����$N" HIY "������ȭ����"
                       "ʽ��Ϊ��\n�ʵ��$N" HIY "ǰ��δ�š�\n" NOR, me,
                       this_object());;

        command("haha");
        command("say ������ˣ�");
        tell_object(me, HIC "��ѧ���ˡ����޽�������\n" NOR);

        if (me->can_improve_skill("cuff"))
                me->improve_skill("cuff", 1500000);
        if (me->can_improve_skill("yujiamu-quan"))
                me->improve_skill("yujiamu-quan", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/yujiamu-quan/jiang", 1);
        me->add("gongxian", -300);

        return 1;
}

mixed ask_skill4()
{
        object me;

        me = this_player();

        if (me->query("can_perform/mingwang-jian/ruo"))
                return "�Լ���ȥ��������ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "����ʲô�ˣ��ҿ�����ô��������Ѫ���ŵĵ����أ�";

        if (me->query_skill("mingwang-jian", 1) < 1)
                return "����������������ûѧ��������ʲô��";

        if (me->query("gongxian") < 100)
                return "����Ϸ�������£��Ϸ���Ȼ�ᴫ�������";

        if (me->query("shen") > -10000)
                return "����������ô���ģ���ɱ�˶������ˣ�";

        if (me->query_skill("force") < 140)
                return "����ڹ���Ϊʵ��̫����������������Ϸ�ɡ�";

        if (me->query("max_neili") < 1200)
                return "������������������Ȼ������˼�����Ϸ�";

        if (me->query_skill("mingwang-jian", 1) < 100)
                return "����Ѳ����������������������Ϸ�";

        message_vision(HIY "$n" HIY "��Цһ����Ҳ���𻰣���$N" HIY "���нӹ�����"
                       "����������\nһ����������ʱ����һ��ͳ������������������"
                       "$N" HIY "ֻ�е���\nͷһ�𣬾�ӿ��һ��Ī���ı�����\n" NOR,
                       me, this_object());

        command("haha");
        command("say ����ܼ򵥣����Լ���ȥ���ɡ�");
        tell_object(me, HIC "��ѧ���ˡ���������\n" NOR);

        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("mingwang-jian"))
                me->improve_skill("mingwang-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/mingwang-jian/ruo", 1);
        me->add("gongxian", -100);

        return 1;
}

mixed ask_skill5()
{
        object me;

        me = this_player();

        if (me->query("can_perform/mingwang-jian/xiang"))
                return "�Լ���ȥ��������ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "����ʲô�ˣ��ҿ�����ô��������Ѫ���ŵĵ����أ�";

        if (me->query_skill("mingwang-jian", 1) < 1)
                return "����������������ûѧ��������ʲô��";

        if (me->query("gongxian") < 400)
                return "����Ϸ�������£��Ϸ���Ȼ�ᴫ�������";

        if (me->query("shen") > -15000)
                return "����������ô���ģ���ɱ�˶������ˣ�";

        if (me->query_skill("force") < 180)
                return "����ڹ���Ϊʵ��̫����������������Ϸ�ɡ�";

        if (me->query("max_neili") < 1600)
                return "������������������Ȼ������˼�����Ϸ�";

        if (me->query_skill("mingwang-jian", 1) < 140)
                return "����Ѳ����������������������Ϸ�";

        message_vision(HIY "$n" HIY "��$N" HIY "΢΢һЦ���漴������֣���ʳ��ָ"
                       "��£������\n���������͡���һ���յ��������ʱ�ƿ�֮������"
                       "��һ������\n��ָ��ŷ�����$N" HIY "��������ɮ�۴�͸��һ��"
                       "С�ס�\n" NOR, me, this_object());

        command("sneer");
        command("say ���в�������Խ���ý���������ˡ�");
        tell_object(me, HIC "��ѧ���ˡ���ħ����\n" NOR);

        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("mingwang-jian"))
                me->improve_skill("mingwang-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/mingwang-jian/xiang", 1);
        me->add("gongxian", -400);

        return 1;
}

mixed ask_skill6()
{
        object me;

        me = this_player();

        if (me->query("can_perform/xuedao-dafa/ying"))
                return "�Լ���ȥ��������ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "����ʲô�ˣ��ҿ�����ô��������Ѫ���ŵĵ����أ�";

        if (me->query_skill("xuedao-dafa", 1) < 1)
                return "����Ѫ���󷨶�ûѧ��������ʲô��";

        if (me->query("gongxian") < 300)
                return "����Ϸ�������£��Ϸ���Ȼ�ᴫ�������";

        if (me->query("shen") > -60000)
                return "����������ô���ģ���ɱ�˶������ˣ�";

        if (me->query_skill("force") < 160)
                return "����ڹ���Ϊʵ��̫����������������Ϸ�ɡ�";

        if (me->query("max_neili") < 1500)
                return "������������������Ȼ������˼�����Ϸ�";

        if (me->query_skill("xuedao-dafa", 1) < 120)
                return "�����Ѫ�����������������Ϸ�";

        message_vision(HIY "$n" HIY "��Цһ������$N" HIY "˵��������ͽ�����Ϸ���"
                       "�͸�����ʾ\nһ�飬�����ˣ���$n" HIY "˵���������Ѫ����"
                       "��Ȼһ����\n�ȣ������е�Ѫ���趯���֣���ʱ���漤����Ѫ"
                       "�˱���$N" HIY "��\nȥ��ֱ������$N" HIY "Ŀ�ɿڴ���\n" NOR,
                       me, this_object());

        command("haha");
        command("say ���е�Ҫ������һ�����֣�������ô��");
        tell_object(me, HIC "��ѧ���ˡ���Ӱ�񵶡���\n" NOR);

        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("blade"))
                me->improve_skill("blade", 1500000);
        if (me->can_improve_skill("xuedao-dafa"))
                me->improve_skill("xuedao-dafa", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/xuedao-dafa/ying", 1);
        me->add("gongxian", -300);

        return 1;
}

mixed ask_skill7()
{
        object me;

        me = this_player();

        if (me->query("can_perform/xuedao-dafa/chi"))
                return "�Լ���ȥ��������ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "����ʲô�ˣ��ҿ�����ô��������Ѫ���ŵĵ����أ�";

        if (me->query_skill("xuedao-dafa", 1) < 1)
                return "����Ѫ���󷨶�ûѧ��������ʲô��";

        if (me->query("gongxian") < 800)
                return "����Ϸ�������£��Ϸ���Ȼ�ᴫ�������";

        if (me->query("shen") > -70000)
                return "����������ô���ģ���ɱ�˶������ˣ�";

        if (me->query_skill("force") < 220)
                return "����ڹ���Ϊʵ��̫����������������Ϸ�ɡ�";

        if (me->query("max_neili") < 2400)
                return "������������������Ȼ������˼�����Ϸ�";

        if (me->query_skill("xuedao-dafa", 1) < 160)
                return "�����Ѫ�����������������Ϸ�";

        message_vision(HIY "$n" HIY "�ٺ�һЦ�����ֽ�$N" HIY "�е���ǰ��������$N"
                       HIY "�����ֹ���\n���졣���$n" HIY "�ְγ������Ѫ��������"
                       "�£��ƺ���һ��\n��Ϊ����ĵ�����\n" NOR, me, this_object());

        command("haha");
        command("say ��Ҫ�Ҷ��������ˣ��Լ���ȥ���ɡ�");
        tell_object(me, HIC "��ѧ���ˡ������񵶡���\n" NOR);

        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("blade"))
                me->improve_skill("blade", 1500000);
        if (me->can_improve_skill("xuedao-dafa"))
                me->improve_skill("xuedao-dafa", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/xuedao-dafa/chi", 1);
        me->add("gongxian", -800);

        return 1;
}

mixed ask_skill8()
{
        object me;

        me = this_player();

        if (me->query("can_perform/xuedao-dafa/xue"))
                return "�Լ���ȥ��������ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "����ʲô�ˣ��ҿ�����ô��������Ѫ���ŵĵ����أ�";

        if (me->query_skill("xuedao-dafa", 1) < 1)
                return "����Ѫ���󷨶�ûѧ��������ʲô��";

        if (me->query("gongxian") < 1000)
                return "����Ϸ�������£��Ϸ���Ȼ�ᴫ�������";

        if (me->query("shen") > -80000)
                return "����������ô���ģ���ɱ�˶������ˣ�";

        if (me->query_skill("force") < 220)
                return "����ڹ���Ϊʵ��̫����������������Ϸ�ɡ�";

        if (me->query("max_neili") < 2400)
                return "������������������Ȼ������˼�����Ϸ�";

        if (me->query_skill("xuedao-dafa", 1) < 160)
                return "�����Ѫ�����������������Ϸ�";

        message_vision(HIY "$n" HIY "���˿�$N" HIY "����Цһ�������˵�ͷ�������ֽ�"
                       "$N" HIY "�е���\nǰ��������$N" HIY "�����ֹ��˰��졣$N" HIY
                       "������ɫ��䣬�ƺ�������\nʲô�������ŵ����飬��$n" HIY "��"
                       "��������һ��$N" HIY "�ı���\n�������ɳ����������漴���ĵ�"
                       "һЦ��������������\n" NOR, me, this_object());

        command("grin");
        command("say ���е�Ҫ��������޷��ˣ�ƴ��һ������ס����");
        tell_object(me, HIC "��ѧ���ˡ���Ѫ�񵶡���\n" NOR);

        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("blade"))
                me->improve_skill("blade", 1500000);
        if (me->can_improve_skill("xuedao-dafa"))
                me->improve_skill("xuedao-dafa", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/xuedao-dafa/xue", 1);
        me->add("gongxian", -1000);

        return 1;
}

mixed ask_skill9()
{
        object me;

        me = this_player();

        if (me->query("can_perform/xuedao-dafa/shi"))
                return "�Լ���ȥ��������ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "����ʲô�ˣ��ҿ�����ô��������Ѫ���ŵĵ����أ�";

        if (me->query_skill("xuedao-dafa", 1) < 1)
                return "����Ѫ���󷨶�ûѧ��������ʲô��";

        if (me->query("gongxian") < 2000)
                return "����Ϸ�������£��Ϸ���Ȼ�ᴫ�������";

        if (me->query("shen") > -100000)
                return "����������ô���ģ���ɱ�˶������ˣ�";

        if (me->query_skill("force") < 250)
                return "����ڹ���Ϊʵ��̫����������������Ϸ�ɡ�";

        if (me->query("max_neili") < 2600)
                return "������������������Ȼ������˼�����Ϸ�";

        if (me->query_skill("xuedao-dafa", 1) < 180)
                return "�����Ѫ�����������������Ϸ�";

        message_vision(HIY "$n" HIY "����$N" HIY "��Ц��������˵�������벻����Ȼ��ô"
                       "�����\n���ܹ��̳�����һ�У���Ѫ�������Ǻ�����˰��������ұ�"
                       "��\n����ʽ����Ѫ�ԡ����������������䣬�漴ֻ��$n" HIY "��\n"
                       "��һ������������Ѫ��һ�񣬶�ʱ�ŷ�������Ѫ�⣬�����ޱ�\nɱ��"
                       "���쵶��������â��չ������һ���޴��Ѫ��$n" HIY "\n��������"
                       "�У�����֮������ʵ������������\n" NOR, me, this_object());

        command("haha");
        command("say ����������Ѫ���к�һ���������С����Լ���ȥ���ɡ�");
        tell_object(me, HIC "��ѧ���ˡ���Ѫ�ԡ���\n" NOR);

        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("blade"))
                me->improve_skill("blade", 1500000);
        if (me->can_improve_skill("blade"))
                me->improve_skill("blade", 1500000);
        if (me->can_improve_skill("blade"))
                me->improve_skill("blade", 1500000);
        if (me->can_improve_skill("parry"))
                me->improve_skill("parry", 1500000);
        if (me->can_improve_skill("parry"))
                me->improve_skill("parry", 1500000);
        if (me->can_improve_skill("parry"))
                me->improve_skill("parry", 1500000);
        if (me->can_improve_skill("xuedao-dafa"))
                me->improve_skill("xuedao-dafa", 1500000);
        if (me->can_improve_skill("xuedao-dafa"))
                me->improve_skill("xuedao-dafa", 1500000);
        if (me->can_improve_skill("xuedao-dafa"))
                me->improve_skill("xuedao-dafa", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/xuedao-dafa/shi", 1);
        me->add("gongxian", -2000);

        return 1;
}

mixed ask_midao()
{
        object me;

        me = this_player();
        if (me->query("family/family_name") != "Ѫ����")
                return "�������̵ģ����ֹ�������Ҫ˵ʲô��";

        command("whisper " + me->query("id") + " ���Ȼ�Ѿ�������������"
                "����\nҪȥ��ԭ���£�����������Ѫ���ȱ������µ��ܵ�����"
                "�ɵ�ɽ\n������Ѵ�����(" NOR + HIY "enter mash" NOR + WHT
                ")��Ȼ����ܵ�����ԭ���ݡ�����\n������Ѫ��������ԭ������"
                "���ӿ�������" NOR + HIR "Ѫ���ޱ�" NOR + WHT "��\n");
        return "�����ܲ���й¶�����ˣ������������";
}

mixed ask_dao()
{
        object me;
        object ob;
        object owner;

        me = this_player();
        if (me->is_good())
        {
                if (me->query("family/family_name") == "Ѫ����")
                        message_vision(CYN "$N" CYN "��ŭ����$n" CYN "����������"
                                       "Ϊ��Ѫ���ŵ��ӣ�����ѧ����ʼ������ˣ���"
                                       "Ȼ����������Ҫ����֮������\n" NOR,
                                       this_object(), me);
                else
                        message_vision(CYN "$N" CYN "��ŭ����$n" CYN "�ȵ�������"
                                       "��ʲô�ˣ���Ȼ��̰ͼ���������������ʿ���"
                                       "�������㣡��\n" NOR,
                                       this_object(), me);
                return 1;
        }

        if (me->query("family/family_name") != "Ѫ����")
                return "Ѫ������Ѫ�������������������ʲô��";

        if (me->query("family/master_id") != query("id"))
                return "ֻ���ҵĵ��Ӳ�����Ѫ�����㻹���Լ���ȥ�����ɡ�";

        if (me->query("shen") > -50000)
                return "��а�����أ�ʹ�ò���Ѫ����";

        ob = find_object(XUEDAO);
        if (! ob) ob = load_object(XUEDAO);
        owner = environment(ob);
        while (owner)
        {
                if (owner->is_character() || ! environment(owner))
                        break;
                owner = environment(owner);
        }

        if (owner == me)
                return "�����̵ģ����ŵ�Ѫ�����ڲ���������������";

        if (objectp(owner) && owner != this_object())
        {
                if (! owner->is_character())
                        return "��������һ����Ѫ�����ڲ��������С�";

                if (owner->query("family/family_name") == "Ѫ����")
                        return "Ѫ��������ʱ����ͬ��ʦ��" + owner->query("name") +
                               "���ã���Ҫ�þ�ȥ�����ɡ�";
                else
                        return "���ŵ�Ѫ����������" + owner->query("name") +
                               "���У���ȥ�������ˣ���Ѫ����������";
        }

        ob->move(this_object());
        message_vision(CYN "$N" CYN "����һЦ�������ã���ͽ�������Ѫ�����"
                       "��ȥ����ɱ����������ʿ���������ǵ����磡\n" NOR,
                       this_object(), me);
        command("give xue dao to " + me->query("id"));
        return 1;
}

mixed ask_book()
{
        object me;
        object ob;
        object owner;

        me = this_player();

        if (me->query("family/family_name") != "Ѫ����")
                return "��������Ұ�֣����Ҵ���Ѫ���ŵ����⣿";

        if (me->query("family/master_id") != query("id"))
                return "���ֲ����Ϸ�ĵ��ӣ����Ϸ�����Щʲô��";

        if (me->query("shen") > -50000)
                return "�㵹��ѧ����ʼ������ˣ����Ϸ�����������㣿";

        if (me->query("combat_exp") < 300000)
                return "�����ھ���̫ǳ���ⱾѪ�����㻹��������";

        if (me->query_skill("xuedao-dafa", 1) > 179)
                return "���Ѫ���󷨻���Ѿ������ˣ�Ѫ������������ʲô���á�";

        ob = find_object(JING);
        if (! ob) ob = load_object(JING);
        owner = environment(ob);
        while (owner)
        {
                if (owner->is_character() || ! environment(owner))
                        break;
                owner = environment(owner);
        }

        if (owner == me)
                return "��Ѫ���ŵı����������������ڿ���";

        if (objectp(owner) && owner != this_object())
        {
                if (! owner->is_character())
                        return "���š�Ѫ�������ڲ��������";

                if (owner->query("family/family_name") == "Ѫ����")
                        return "Ѫ����������ʱ����ͬ�ŵ�" + owner->query("name") +
                               "ȡȥ���ˣ���Ҫ����ȥ�����ɡ�";
                else
                        return "��Ѫ���ŵı�������������" + owner->query("name") +
                               "���У���ȥ����������ɣ�";
        }
        ob->move(this_object());
        message_vision(CYN "$N" CYN "��ͷ�����ⱾѪ���������ȥ���ɣ���Ҫ��ϸ�Ķ���\n" NOR,
                       this_object(), me);
        command("give xuedao jing to " + me->query("id"));
        return 1;
}

int accept_object(object me, object ob)
{
        int r;
        if (r = ::accept_object(me, ob))
                return r;

        if (base_name(ob) != XUEDAO)
        {
                command("say ��������ֶ�����ʲô��");
                return 0;
        }

        if (me->query("family/master_id") != query("id"))
                command("say ��������");
        else
                command("say �ܺã��ܺã�");
        destruct(ob);
        return 1;
}

void unconcious()
{
        die();
}