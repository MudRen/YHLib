#include <ansi.h>

inherit NPC;
inherit F_DEALER;

int do_liandan();
string ask_me();
string ask_yinzhen();

void create()
{
        set_name("Ҧ��", ({"yao chun", "yao", "chun"}));
        set("gender", "����");
        set("age", 56);
        set("title", HIG "�ش���" NOR);
        set("nickname", HIR "������ҽ" NOR);
        set("long",
                "����Ǿ��ǻش���ҩ�̵ĵ�����ҽҦ������ĸ�\n"
                "�ݣ���ò���������ػ����촨�����ˣ�����\n"
                "��ҽ�Σ����˼�����ҽ�����ö̴�Ҳ��һ����\n");
        set("attitude", "heroism");
        set("shen_type",1);
        set("str", 32);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("qi", 20000);
        set("max_qi", 20000);
        set("jing", 1600);
        set("max_jing", 1600);
        set("neili", 20000);
        set("max_neili", 20000);

        set("combat_exp", 10000000);
        set("score", 300000);

        set_skill("medical", 150);
        set_skill("zhenjiu-shu", 150);
        set_skill("liandan-shu", 150);
        set_skill("literate", 150);

        map_skill("medical", "bencao-shuli");

        set("inquiry", ([
                "���촨"  :  "���Ϻ�������Ҹ�ҽ�εģ���ô��Ҳ֪����\n",
                "����"    : (:do_liandan:),
                "liandan" : (:do_liandan:),
                "quest"   :  "����������԰����ҡ�" HIR "����" NOR + CYN
                             "�������Ը���������ѯ�ʡ�\n",
                "job"     :  "����������԰����ҡ�" HIR "����" NOR + CYN
                             "�������Ը���������ѯ�ʡ�\n",
                "ҩ��"    :  "ȥ���ҵ�Сͯ��������㴦��\n",
                "ԭ��"    :  "ȥ���ҵ�Сͯ��������㴦��\n",
                "yaocai"  :  "ȥ���ҵ�Сͯ��������㴦��\n",
                "ҩ"      :  "ȥ���ҵ�Сͯ��������㴦��\n",
                "ҽ��"    : (: ask_me :),
                "ѧҽ��"  : (: ask_me :),
                "ѧϰҽ��": (: ask_me :),
                "������"  : (: ask_me :),
                "�����"  : (: ask_me :),
                "��������": (: ask_me :),
                "����ҽ��": (: ask_me :),
                "ѧϰ"    : (: ask_me :),
                "ѧ��"    : (: ask_me :),
                "����"    : (: ask_yinzhen :),
                "��"      : (: ask_yinzhen :),
                "���"    : (: ask_yinzhen :),
        ]));
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/book/mbook3");
        carry_object("/clone/book/mbook4");
}


void init()
{
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

int do_liandan()
{
        int exp, pot;
        object me = this_player();

        if (me->query_temp("liandan"))
        {
                if (me->query_temp("liandan") < 4)
                {
                        command("say ����Ҫȥ��������ô��������ţ�\n");
                        return 1;
                }
                message_vision(CYN "Ҧ����$N" CYN "΢Ц���������Ǹ��������Ե�"
                               "���̣����ܳɹ����ܲ���\n" NOR, me);

                exp = 8 + random(5);
                pot = 2 + random(3);

                me->add("combat_exp", exp);
	        me->improve_potential(pot);

                if (me->query("potential") > me->query_potential_limit()) 
			pot = 1;

                tell_object(me, HIC "������" + chinese_number(exp) +
                                "�㾭���" + chinese_number(pot) + "��Ǳ�ܡ�\n"
                                NOR );

                me->delete_temp("liandan");
                me->add("over_quest/liandan_quest", 1);
                return 1;
        } else
	{
                message_vision(CYN "Ҧ����$N" CYN "���˵�ͷ��˵���������ǿ���"
                               "�˵Ķ�����Ϊ���Ĳ������²��ɣ���ȥ��ͯ��ѯ�ʡ�"
                               HIG "ҩ��" NOR + CYN "���ɡ�\n", me);
                me->set_temp("liandan", 1);
                return 1;
        }
}

string ask_me() 
{
        object me;

        me = this_player();

        if (me->query("can_learn_medical/yaochun") == 1)
                return "�Ҳ��Ǵ�Ӧ����������������ô��ô���£�";

        if (me->query("shen") < -10000)
                return "������ħͷ����ȥɱ�˶��������ִ����ˡ�";

        if (me->query("over_quest/liandan_quest") < 100 )
                return "�����ɣ����Ȱ��������ٴΣ��ĳ�֮ʱ����Ȼ�ᴫ�ڸ��㡣";

        if (me->query("shen") < 0)
                return "�������������ò������������֮������Ȼ�ᴫ�ڸ��㡣";

        me->set("can_learn_medical/yaochun", 1);
               return "��Ȼ������������ѧҽ֮�����Ҿͳ�ȫ��ȫ��ɡ�"; 
}

int recognize_apprentice(object me, string skill)
{
        if (me->query("shen") < -10000)
        {
                command("say ���ҹ������Ҳ��ᴫ���κμ��ܸ�������ħͷ��");
                return -1;
        }

        if ( ! me->query("can_learn_medical/yaochun") )
        {
                command("say �ҵ�ҽ�������ǲ����״��ڵġ�");
                return -1;
        }

        if (skill == "literate")
        {
                command("say ����д���Լ�ȥ�ҽ�������ѧȥ��");
                return -1;
        }

        if (skill != "medical" &&
            skill != "zhenjiu-shu")
        {
                command("say ��ֻ�ܴ��ڻ���ҽ�����������");
                return -1;
        }

        return 1;
}

string ask_yinzhen()
{
        mapping fam; 
        object ob;
        object me = this_player();

        if (me->query("shen") < -0)
                return "���߰ɣ��ҵ�����ɲ�������������ˡ�";

        if ((int)me->query_skill("zhenjiu-shu", 1) < 60)
                return "�������������죬��������Ū���������ġ�";

        if (present("yin zhen", this_player()))
                return "�����ϲ��ǻ���һ����";

        ob = new("/d/beijing/obj/yinzhen");
        ob->move(me);

        message_vision(HIW "\nҦ����������������һ�����룬�ݸ���$N" HIW "��\n" NOR, me);
                return "����������������ģ��úõ�������Ϊ���β��ɡ�";
}

