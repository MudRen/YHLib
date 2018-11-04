#include <ansi.h>
#include "quanzhen.h"

inherit NPC;
inherit F_MASTER;
inherit F_GUARDER;

void check_body();
mixed ask_skill1();

void create()
{
        set_name("�𴦻�", ({ "qiu chuji", "qiu", "chuji" }));
        set("long", @LONG
�����ǽ������˳Ƴ����ӵ��𴦻������ˣ���
���÷������������⣬��ĿԲ����˫ü��
������ò���ϣ�ƽ���������
LONG);
        set("nickname", HIM "������" NOR);
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
        set("max_qi", 5000);
        set("max_jing", 4000);
        set("neili", 5000);
        set("max_neili", 5000);
        set("jiali", 200);

        set("combat_exp", 2600000);

        set_skill("force", 240);
        set_skill("quanzhen-xinfa", 240);
        set_skill("xuanmen-neigong", 240);
        set_skill("sword", 260);
        set_skill("qixing-jian", 240);
        set_skill("tonggui-jian", 260);
        set_skill("quanzhen-jian", 260);
        set_skill("dodge", 240);
        set_skill("tianshan-feidu", 220);
        set_skill("jinyan-gong", 240);
        set_skill("parry", 240);
        set_skill("strike", 220);
        set_skill("chongyang-shenzhang", 220);
        set_skill("haotian-zhang", 220);
        set_skill("hand", 220);
        set_skill("qixing-shou", 220);
        set_skill("finger", 220);
        set_skill("zhongnan-zhi", 220);
        set_skill("literate", 240);
        set_skill("taoism", 200);
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

        set("coagents", ({
                ([ "startroom" : "/d/quanzhen/shiweishi",
                   "id"        : "ma yu" ]),
                ([ "startroom" : "/d/quanzhen/wanwutang",
                   "id"        : "wang chuyi" ]),
        }));

        set("inquiry", ([
                "��ʯ���" : (: ask_skill1 :),
        ]) );

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: check_body :),
                (: perform_action, "sword.ding" :),
                (: perform_action, "sword.chan" :),
                (: perform_action, "hand.po" :),
                (: perform_action, "strike.ju" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }));

        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/quanzhen/npc/obj/grayrobe")->wear();
}

void init()
{       
        object ob;

        ::init();

        if (interactive(ob = this_player()) && ! is_fighting())
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        mapping fam;
        int i ;
        object me = this_object();

        if (! ob || environment(ob) != environment() || ! living(me))
                return;

        if (interactive(ob) && base_name(environment()) == query("startroom"))
        {
                if (! (fam = ob->query("family")) || fam["family_name"] != "ȫ���")
                {
                        if (ob->is_not_bad())
                        {
                                command("hmm");
                                command("say �����Ǳ����صأ����߶�С��Щ��");
                        } else
                        {
                                command("say ����ħͷ�����Ҵ�����ȫ���صأ����У�");
                                kill_ob(ob);
                        }
                }
        }
}

void check_body()
{
        object weapon, guard;
        object me = this_object();
        object where = environment(me);

        if (! objectp(weapon = me->query_temp("weapon"))
           || me->query("eff_qi") > me->query("max_qi") / 2
           || objectp(guard = present("ma yu", where))
           || objectp(guard = present("wang chuyi", where)))
                return;

        message_vision(HIR "\n$N" HIR "һ������" + weapon->name() +
                       HIR "���ȵ�����ɱ�����ӣ��������Ҿ�ƴ������"
                       "���ƣ�\n\n" NOR, me);

	me->set("max_neili", 6500);  // ����ͬ�齣�����е�������
	me->set("neili", 6500);

        command("jifa sword tonggui-jian");
        set("chat_msg_combat", ({
                (: perform_action, "sword.fen" :),
                (: exert_function, "recover" :),
        }));
        set("chat_chance", 120);
        set("chat_msg", ({
                (: command("jifa sword quanzhen-jian") :),
        }));
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query_skill("xuanmen-neigong", 1) < 100
           && (int)ob->query_skill("quanzhen-xinfa", 1) < 100)
        {
                command("hmm");
                command("say ����������������ڹ���δ���㣬����������㣿");
                return;
        }

        if ((int)ob->query_skill("sword", 1) < 100)
        {
                command("sneer");
                command("say ��Ľ����������������ܹ�ɱ�У�");
                return;
        }

        if ((int)ob->query("shen") < 25000)
        {
                command("say ��Ŀǰ����̫�������������������������ң�\n");
                return;
        }

        command("nod");
        command("say ����������ǣ�����ɱ�������ȫ�����ӵ���ͷ��");
        command("say ����ĳ����֪��������������������ɱ���㡣");
        command("recruit " + ob->query("id"));
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/tonggui-jian/fen"))
                return "�Ҳ����Ѿ�����������������ôƾ�����£�";

        if (me->query("family/family_name") != query("family/family_name"))
                return "������ƶ���ز���ʶ����֪�˻��Ӻ�˵��";

        if (me->query_skill("tonggui-jian", 1) < 1)
                return "����ͬ�齣����ûѧ����̸���п��ԣ�";

        if (me->query("gongxian") < 600)
                return "������ȫ�����������Ϊ����������ʱ�����ܴ��㡣";

        if (me->query("shen") < 30000)
                return "����������»����ò�������������ʱ�����ܴ��㡣";

        if (me->query_skill("tonggui-jian", 1) < 120)
                return "���ͬ�齣��������죬���ߵ������ɡ�";

        if (me->query_skill("force") < 150)
                return "����ڹ���Ϊ�����������ߺ��������Ұɡ�";

        if (me->query("max_neili") < 1500)
                return "���������Ϊ�����������ߺ��������Ұɡ�";

        message_sort(HIY "\n$n" HIY "$n" HIY "����һЦ���޵�����������־"
                     "�����ѵ���ȫ�������������˲ģ�����Ϊʦ�ʹ���������"
                     "����Ҫʱ�͵���ͬ���ھ�����Ϊ���飬��Ϊ��ȫ����˵��$n"
                     HIY "��ӻ�������ȡ����һ�����ף�ָ������һ�ζ�$N" HIY
                     "ϸ˵���ã�$N" HIY "һ����һ�ߵ�ͷ��\n\n" NOR, me,
                     this_object()); 

        command("nod");
        command("say ��˵���������ʣ��������򲻵��ѣ�ҲĪҪ����ʹ�á�");
        tell_object(me, HIC "��ѧ���ˡ���ʯ��١���\n" NOR);
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("tonggui-jian"))
                me->improve_skill("tonggui-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/tonggui-jian/fen", 1);
        me->add("gongxian", -600);

        return 1;
}
