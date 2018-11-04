#include <ansi.h>
inherit NPC;

#define HEILONG    "/clone/lonely/heilongbian"
#define LING       "/clone/lonely/item/tongjiling"

void create()
{
        object ob;
        set_name("éʮ��", ({ "mao shiba", "mao", "shiba" }));
        set("long", @LONG
��������Ҳݣ�����Ѫ�ۣ��������ܹ����ص�
�ˣ����Կ��ü���������Ѫ��δ�ɡ�����˫Ŀ
������ȴ������˵���������硣
LONG);
        set("title", "�ٸ�ͨ��Ҫ��");
        set("gender", "����");
        set("age", 30);
        set("str", 25);
        set("dex", 16);
        set("max_qi", 500);
        set("max_jing", 300);
        set("neili", 800);
        set("max_neili", 800);
        set("jiali", 50);
        set("combat_exp", 300000);
        set("shen_type", 1);
        set("attitude", "peaceful");

        set_skill("force", 100);
        set_skill("bagua-xinfa", 100);
        set_skill("blade", 120);
        set_skill("wuhu-duanmendao", 120);
        set_skill("cuff", 120);
        set_skill("hua-quan", 120);
        set_skill("dodge", 100);
        set_skill("feiyan-zoubi", 100);
        set_skill("parry", 100);
        set_skill("literate", 60);
        set_skill("martial-cognize", 80);

        map_skill("blade", "wuhu-duanmendao");
        map_skill("parry", "wuhu-duanmendao");
        map_skill("force", "bagua-xinfa");
        map_skill("dodge", "feiyan-zoubi");
        map_skill("cuff", "hua-quan");

        prepare_skill("cuff", "hua-quan");

        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
        set_temp("apply/armor", 100);
        set_temp("apply/damage", 50);
        set_temp("apply/unarmed_damage", 50);

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "cuff.juan" :),
                (: perform_action, "blade.duan" :),
                (: exert_function, "recover" :),
        }));

        set("inquiry", ([
                "ʷ��"   : "˭ɱ��ʷ����������ҿ��԰�����߽���������",
                "���־�" : "���ܵ������ְɣ�",
        ]));

        set("chat_chance", 2);
        set("chat_msg", ({
                CYN "éʮ��˵��: �����̵ģ��ҾͲ����������������������Ҫ�ϱ���ȥ����һ����\n" NOR,
                CYN "éʮ��̾��: �����廢���ŵ����Ը����ɿ��Ǵ´����࣬��֪�Ը������в��С�\n" NOR,
                CYN "éʮ��˵��: �����̵ģ�Ҫ˭����ɱ��ʷ�ɣ��ֵ��Ҿ�лл�ˡ�\n" NOR,
                CYN "éʮ������˵������������Ϊ�˲�ʶ�½��ϣ��ͳ�Ӣ��Ҳ��Ȼ��\n" NOR,
                (: random_move :)
        }) );
        setup();
        if (clonep())
        {
                ob = find_object(LING);
                if (! ob) ob = load_object(LING);
                if (! environment(ob))
                {
                        ob->move(this_object());
                        set_temp("handing", ob);
                }
        }
        carry_object("/d/city/obj/gangdao")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

int accept_object(object me, object ob)
{
        int exp, pot, sc;

        exp = 500 + random(300);
        pot = 100 + random(50);
        sc = random(10);

        if (base_name(ob) != HEILONG)
        {
                command("say ��������ֶ�����ʲô��");
                return 0;
        }

        if (me->query("combat_exp") > 10000)
        {
        	if (! (int)me->query("skybook/luding/mao"))
        	{
                	me->add("combat_exp", exp);
                	me->add("potential", pot);
                	me->add("score", sc);
                	tell_object(me, HIW "\n\n��ɹ��İ���éʮ��Ū���˺����ޣ�\n" NOR +
                                        HIC "ͨ����ε�������������" + chinese_number(exp) +
                                        "�㾭�顢" + chinese_number(pot) + "��Ǳ���Լ�" +
                                	chinese_number(sc) + "�㽭��������\n\n" NOR);
                	me->set("skybook/luding/mao", 1);
                	me->set("can_learn/wuhu-duanmendao/mao", 1);
		}
                command("haha");
                command("say ��л����л���Ǹ������Ӱ�������ȥ�ˡ�");
                command("say ������һ���廢���ŵ�����������⣬���ǿ��Կ�����\n");
        } else
	{
                command("pat " + me->query("id"));
                command("say Ҫ������Ľ�������̫ǳ�����������㶫����");
	}
        destruct(ob);
        return 1;
}

int recognize_apprentice(object me, string skill)
{
        if (! me->query("can_learn/wuhu-duanmendao/mao"))
        {
                command("say ���û��ʦ������ѧ������");
                return -1;
        }

        if (skill != "wuhu-duanmendao")
        {
                command("say ����ֻ����һ�׵����õó��֡�");
                return -1;
        }
        return 1;
}
