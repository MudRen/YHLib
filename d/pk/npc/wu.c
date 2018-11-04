#include <ansi.h>;
#include "/kungfu/class/lingjiu/etc.h"

#define XIANGLUDAO  "/clone/lonely/xiangludao"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;

mixed ask_me();
mixed ask_dao();
mixed ask_skill();

void create()
{
        object ob;
        set_name("���ϴ�", ({ "wu laoda", "wu", "laodao" }));
        set("gender", "����");
        set("title", "�ؽ��̵�������");
        set("age", 45);
        set("long", @LONG
һλ��Ŀ���ĺ��ӣ��������룬����������
�䡣�����ǻؽ��̵����������ϴ�������ɽ
��翷����չ�����֯�����ɴ�ᣬԤı������
ɽͯ�ѣ���������������������
LONG );
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
    
        set("qi", 4500);
        set("max_qi", 4500);
        set("jing", 2200);
        set("max_jing", 2200);
        set("neili", 4800);
        set("max_neili", 4800);
        set("jiali", 150);
        set("combat_exp", 2200000);

        set_skill("force", 200);
        set_skill("yaogu-xinfa", 200);
        set_skill("blade", 200);
        set_skill("biyan-dao", 200);
        set_skill("dodge", 180);
        set_skill("feiyan-zoubi", 180);
        set_skill("hand", 180);
        set_skill("jiuqu-zhegufa", 180);
        set_skill("parry", 180);
        set_skill("martial-cognize", 180);
        set_skill("literate", 120);

        map_skill("force", "yaogu-xinfa");
        map_skill("blade", "biyan-dao");
        map_skill("dodge", "feiyan-zoubi");
        map_skill("parry", "biyan-dao");
        map_skill("hand", "jiuqu-zhegufa");

        prepare_skill("hand", "jiuqu-zhegufa");

        set("inquiry", ([
                "������"     : (: ask_me :),
                "���˴���"   : (: ask_me :),
                "���˱���"   : (: ask_me :),
                "�������"   : (: ask_skill :),
                "�̲���¶��" : (: ask_dao :),
        ]));

        set("count", 1);

        create_family("�̵���", 7, "����");

        setup();

        if (clonep())
        {
                ob = find_object(XIANGLUDAO);
                if (! ob) ob = load_object(XIANGLUDAO);
                if (! environment(ob))
                {
                        ob->move(this_object());
                        ob->wield();
                } else
                {
                        ob = new("/clone/weapon/gangdao");
                        ob->move(this_object());
                        ob->wield();
                }
        }

        carry_object("/clone/cloth/cloth")->wear();
}

int recognize_apprentice(object ob, string skill)
{
        if (ob->query("family/family_name") != "���չ�")
        {
                command("heng");
                command("say �������ĳ�������Ȼ���𰳵��������ˣ�");
                return -1;
        }

        if (ob->query("family/master_id") != "xuzhu zi")
        {
                command("grin");
                command("say ���������չ�����ֲ�����˵����");
                return -1; 

        }

        if (skill != "biyan-dao" && skill != "blade")
        {
                command("consider");
                command("say ��ֻ�ܽ���һЩ�������������㻹�Ǹ�����ѧ�ɡ�");
                return -1;
        }

        if (skill == "blade" && ob->query_skill("blade", 1) > 179)
        {
                command("hmm");
                command("say ���Ѿ�ѧ�ò���ˣ�ʣ�µľ��Լ�ȥ�о��ɡ�");
                return -1;
        }

        if (! ob->query_temp("can_learn/wulaoda"))
        {
                command("qnod");
                command("say ��Ȼ�����Ȥ�����������ĵ��ӣ���ĳ�ͽ������ױ��̵�����");
                ob->set_temp("can_learn/wulaoda", 1);
        }
        return 1;
}

mixed ask_skill()
{
        object me;

        me = this_player();
        if (me->query("can_perform/biyan-dao/luo"))
                return "���Ѿ�˵�ù����ˣ�����Ҿ������ݡ�";

        if (me->query("family/family_name") != "���չ�" &&
           me->query("family/family_name") != "�̵���")
                return "�ߣ���֪�����⻰��ʲô��˼��";

        if (me->query_skill("biyan-dao", 1) < 1)
                return "����̵�����δ����������̸ʲô���С�";

        if (me->query("family/family_name") == "���չ�" &&
           me->query("gongxian") < 250)
                return "����������ô������޹��͵ĵ��ӡ�";

        if (me->query_skill("force") < 120)
                return "����ڹ���������������ʲô������";

        if ((int)me->query("max_neili", 1) < 1000)
                return "���������������������ʲô������";

        if (me->query_skill("biyan-dao", 1) < 80)
                return "��ı��̵�����򻹲��Զ���ٻ�ȥ������";

        message_vision(HIY "$n" HIY "���һ㶣��漴��Ц���������ֽ�$N"
                       HIY "�е���ǰ��������$N" HIY "������\n���˰���"
                       "����ʱ���γ��������輸�£��ƺ���һ����Ϊ�����"
                       "������\n" NOR, me, this_object());
        command("haha");
        command("say ������㣬���Լ���ȥ�ɡ�");
        tell_object(me, HIC "��ѧ���ˡ������������\n" NOR);

        if (me->can_improve_skill("blade"))
                me->improve_skill("blade", 1500000);
        if (me->can_improve_skill("biyan-dao"))
                me->improve_skill("biyan-dao", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/biyan-dao/luo", 1);
        if (me->query("family/family_name") == "���չ�")
                me->add("gongxian", -250);
        return 1;
}

mixed ask_dao()
{
        object me;
        object ob;
        object owner;

        me = this_player();

        if (me->query("family/family_name") != "���չ�" &&
           me->query("family/family_name") != "�̵���")
                return "�������ĳ�������Ȼ�Ҵ򰳱��������⣡";

        if (me->query("family/master_id") != "xuzhu zi" &&
           me->query("family/master_id") != "wu laoda")
                return "�ҵı����ɲ����κ��˶����õģ�Ҫ������ʦ�����á�";

        if (me->query_skill("biyan-dao", 1) < 100)
                return "�㻹���ȸ���ѧ�㵶���ɡ�";

        ob = find_object(XIANGLUDAO);
        if (! ob) ob = load_object(XIANGLUDAO);
        owner = environment(ob);
        while (owner)
        {
                if (owner->is_character() || ! environment(owner))
                        break;
                owner = environment(owner);
        }

        if (owner == me)
                return "�ҵı���������������������";

        if (objectp(owner) && owner != this_object())
        {
                if (! owner->is_character())
                        return "��������һ�����ҵı����Ѿ��ñ���ȡȥ�ˡ�";

                if (owner->query("family/family_name") == "�̵���")
                        return "�ҵı�����������ͽ��" + owner->query("name") +
                               "���ã���Ҫ�þ�ȥ�����ɡ�";
                else
                if (owner->query("family/family_name") == "���չ�")
                        return "�ҵı������������չ���" + owner->query("name") +
                               "ȡȥ�ˣ���Ҫ�þ�ȥ�����ɡ�";
                else
                        return "�ҵı��������䵽��" + owner->query("name") +
                               "���У���ȥ�����ɣ�";
        }
        ob->move(this_object());

        ob = new("/clone/weapon/gangdao");
        ob->move(this_object());
        ob->wield();
        message_vision(CYN "$N" CYN "̾�������ˣ����ˣ����ⱦ�������ȥ�ðɣ���"
                       "��Ū���ˡ�\n" NOR, this_object(), me);
        command("give xianglu dao to " + me->query("id"));

        if (query("count") > 0)
	{
        	ob = new("/d/lingjiu/npc/obj/yuping");
        	ob->move(this_object());
        	command("say ���⣬�⵶��ͿĨ�����Ҷ�����ҩ����ƿ��ҩ��Ҳ���ţ�"
                        "�Ա���ʱ֮�衣");
        	command("give yu ping to " + me->query("id"));
	        add("count", -1);
	}
        return 1;
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        command("haha");
        command("say ��������");
        command("say �һؽ��̵����˲�ϡ�٣�������������֮ʱ����������ɡ�");
        command("recruit " + ob->query("id"));
}

void init()
{
        add_action("do_sign", "sign");
        add_action("do_join", "join");
}

mixed ask_me()
{
        object me;

        me = this_player();
        if (PK_D->is_pking())
                return "�������˴������ھ����أ������ʲô��";

        if (PK_D->is_ready())
                return "�ܺã��������˴�����Ҫ��ʼ����Ҫ����(sign)ô��";

        return "���˴��������������Űɡ�Ҫ�����ģ�����Ҫ�����ȥ����(join)Ҳ�С�";
}

int do_sign()
{
        object me;
        string msg;
        object ob;

        me = this_player();
        message_vision(CYN "\n$N" CYN "����Ц����$n" CYN "�������ã����ã���"
                       "Ҳ��ǩ������\n" NOR, me, this_object());
        if (me->query("combat_exp") < 1000)
        {
                message_vision(CYN "$n" CYN "̧ͷ���˿�$N" CYN "����м������"
                               "����㱾�£�ֻ�òμӱ���������\n" NOR, me,
                               this_object());
                return 1;
        }

        if (stringp(msg = PK_D->reject_join(me)))
        {
                command("say " + msg);
                return 1;
        }

        foreach (ob in deep_inventory(me))
                if (ob->is_character())
                {
                        command("say �㱳��˭��ȥ�������ϼҴ��ڵģ�����ҹ���");
                        message_vision(HIC "$N" HIC "����һ�ţ���$n" HIC "��"
                                       "���ڵأ�\n" NOR, this_object(), me);
                        me->receive_damage("qi", 50);
                        return 1;
                }

        message_vision(CYN "$n" CYN "���ͷ����$N" CYN "�����ܺã��ܺã�����"
                       "��ȥ׼���ɡ�\n\n" HIY "$N" HIY "���ͷ�������׼��"
                       "����ȥ��\n" NOR, me, this_object());
        me->move("/d/pk/ready");
        message("vision", HIW + me->name() + HIW "�����ӵ����˽�����\n" NOR,
                          environment(me), ({ me }));
        return 1;
}

int do_join()
{
        return notify_fail(CYN "���ϴ�ŭ����������ʲô������������Ĳ�������"
                           "�����涼�����ˡ�\n" NOR);

        if (PK_D->is_pking())
                return notify_fail(CYN "���ϴ�üͷһ��������������������أ�"
                                   "����Щ�˵ȵȰɡ�\n" NOR);

        if (PK_D->is_ready())
                return notify_fail(CYN "���ϴ���������Ҫ����ʽ�����ͽ�ȥ����"
                                   "�����ȵ��š�\n" NOR);

        message_vision(CYN "$N" CYN "��Ц��$n" CYN "�����ҽ�ȥ���������"
                       "�ɺã�\n" NOR, this_player(), this_object());

        if (PK_D->join_competition(this_player()))
        {
                message("vision", HIW + this_player()->name() + HIW "һ��С��"
                        "�������˳���\n" NOR, environment());
                return 1;
        }
        return 0;
}

void unconcious()
{
        die();
}
