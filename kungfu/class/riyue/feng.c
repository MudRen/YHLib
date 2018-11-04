#include <ansi.h>
#include "riyue.h"

#define SHENMU    "/clone/lonely/shenmu"

inherit NPC;
inherit F_MASTER;

mixed ask_back();
mixed ask_gun();
mixed ask_skill1();

void create()
{
	object ob;
        set_name("�ų˷�", ({"zhang chengfeng", "zhang", "chengfeng", "feng"}));
        set("nickname", HIY "�����ħ" NOR );
        set("title", "�������ǰ������");
        set("long", @LONG
�����ħ�ų˷���������̵�ǰ�����ϣ��书
��ǿ��λ���ޱȡ���һ��ɨ�������������ˡ�
LONG);
        set("gender", "����");
        set("class", "scholar");
        set("age", 61);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 36);
        set("int", 36);
        set("con", 36);
        set("dex", 36);
        
        set("max_qi", 5400);
        set("max_jing", 4000);
        set("neili", 7000);
        set("max_neili", 7000);
        set("jiali", 220);
        set("combat_exp", 3000000);
        set("score", 50000);

        set_skill("force", 260);
        set_skill("tianhuan-shenjue", 260);
        set_skill("riyue-xinfa", 220);
        set_skill("dodge", 220);
        set_skill("juechen-shenfa", 220);
        set_skill("cuff", 240);
        set_skill("zhenyu-quan", 240);
        set_skill("claw", 240);
        set_skill("poyue-zhao", 240);
        set_skill("parry", 240);
        set_skill("hammer", 220);
        set_skill("pangu-qishi", 220);
        set_skill("club", 260);
        set_skill("jinyuan-gun", 260);
        set_skill("martial-cognize", 240);
        set_skill("literate", 180);

        map_skill("dodge", "juechen-shenfa");
        map_skill("force", "tianhuan-shenjue");
        map_skill("hammer", "pangu-qishi");
        map_skill("club", "jinyuan-gun");
        map_skill("parry", "jinyuan-gun");
        map_skill("cuff", "zhenyu-quan");
        map_skill("claw", "poyue-zhao");

        prepare_skill("claw", "poyue-zhao");
        prepare_skill("cuff", "zhenyu-quan");

        create_family("�������", 7, "ǰ������");

        set_temp("apply/damage", 200);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        set("inquiry", ([
                "�Ϻ���ľ" : (: ask_gun :),
                "Ǭ��һ��" : (: ask_skill1 :),
                "����" : (: ask_back :),
                "����" : (: ask_back :),
                "��ȥ" : (: ask_back :),
        ]));

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "club.qian" :),
                (: perform_action, "cuff.tong" :),
                (: perform_action, "claw.duan" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}) );

        setup();

        if (clonep())
        {
                ob = find_object(SHENMU);
                if (! ob) ob = load_object(SHENMU);
                if (! environment(ob))
                {
                        ob->move(this_object());
                        ob->wield();
                } else
                {
                        ob = new("/d/heimuya/npc/obj/shutonggun");
                        ob->move(this_object());
                        ob->wield();
                }
        }
        carry_object("/d/heimuya/npc/obj/jinpao")->wear();
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        command("say �߿����Ҳ���ͽ��");
}

int recognize_apprentice(object ob, string skill)
{
        if (ob->query("family/family_name") != "�������")
        {
                command("killair");
                command("say ���ҹ����������Ϸ���ǰ˵�����ģ�");
                return -1;
        }

        if (ob->query("family/master_id") != "ren woxing"
           && ob->query("family/master_id") != "xiang wentian")
        {
                command("sneer");
                command("say �㻹���䡣");
                return -1; 
        }

        if ((int)ob->query("shen") > -60000)
        {
                command("hmm");
                command("say �Ϸ���ƽ��ʹ�޵ľ����������ļ��ʼ���֮ͽ��");
                return -1;
        }

        if (skill != "club" && skill != "jinyuan-gun")
        {
                command("hmm");
                command("say ��ֻ���������׹��������������ʦ��ѧȥ��");
                return -1;
        }

        if (skill == "club" && ob->query_skill("club", 1) > 179)
        {
                command("say ������������Ѿ���ͬ�����ˣ�ʣ�¾��Լ�ȥ���ɡ�");
                return -1;
        }

        if (! ob->query_temp("can_learn/zhangchengfeng"))
        {
                command("nod");
                command("say ����������Ϊ���̳������Ҿʹ������׽�Գ������");
                ob->set_temp("can_learn/zhangchengfeng", 1);
        }
        return 1;
}

mixed ask_gun()
{
        object me;
        object ob;
        object owner;

        me = this_player();

        if (me->query("family/family_name") != "�������")
                return "���ҹ�����";

        if (me->query("family/master_id") != "ren woxing"
           && me->query("family/master_id") != "xiang wentian")
                return "�㻹���䣡";

        if (me->query("shen") > -80000)
                return "�������Ĵ�����������ľ����ʲô�ã�";

        if (me->query_skill("jinyuan-gun", 1) < 120)
                return "������Գ������ûѧ�ã���������������к��ã�";

        ob = find_object(SHENMU);
        if (! ob) ob = load_object(SHENMU);
        owner = environment(ob);
        while (owner)
        {
                if (owner->is_character() || ! environment(owner))
                        break;
                owner = environment(owner);
        }

        if (owner == me)
                return "�Ϻ���ľ���ڲ�������������";

        if (objectp(owner) && owner != this_object())
        {
                if (! owner->is_character())
                        return "��������һ�����Ϻ���ľ���Ѿ����ȥ�ˡ�";

                if (owner->query("family/family_name") == "�������")
                        return "�Ϸ���Ϻ���ľ������" + owner->query("name") +
                               "���ã���Ҫ�þ�ȥ�����ɡ�";
                else
                        return "�Ϸ���Ϻ���ľ����������" + owner->query("name") +
                               "֮�֣���ȥ����ȡ�����ɣ�";
        }
        ob->move(this_object());

        command("say ��Ȼ�������Ϸ�����Ϻ���ľ�����ȥ��");
        command("say ��������ɱ����������ʿ������զ��������̵����硣");
        command("give nanhai shenmu to " + me->query("id"));

        ob = new("/d/heimuya/npc/obj/shutonggun");
        ob->move(this_object());
        ob->wield();
        return 1;
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/jinyuan-gun/qian"))
                return "��һ���Ҳ����Ѿ��̹�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "���ֲ�����������̵ģ�������ʲô�ң�";

        if (me->query_skill("jinyuan-gun", 1) < 1)
                return "������Գ������ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 800)
                return "���ڽ���������Ϊ����������ʱ�����ܴ��㡣";

        if (me->query("shen") > -100000)
                return "�������Ĵ���������ѧ����������ʲô�ã�";

        if (me->query_skill("force") < 180)
                return "����ڹ����������ߣ��������������Ұɡ�";

        if (me->query_skill("jinyuan-gun", 1) < 120)
                return "��Ľ�Գ���������ò����ң��Լ���ȥ���������ɣ�";

        message_sort(HIY "\n$n" HIY "����һ������$N" HIY "���˵�ͷ��������"
                     "���ˣ���˵������ǰ��ŭ��һ����������ͭ�������趯"
                     "����ʱ���ɳ��ʯ����������������ǿ�ɳ쫷��У�$n" HIY
                     "��Ȼ�߸�Ծ��ӭͷһ����Ȼ���䡣����һ���ǳɣ�����֮"
                     "����ɷΪ׳�ۡ�\n\n" NOR, me, this_object()); 

        command("nod2");
        command("say ������ô��");
        tell_object(me, HIC "��ѧ���ˡ�Ǭ��һ������\n" NOR);
        if (me->can_improve_skill("club"))
                me->improve_skill("club", 1500000);
        if (me->can_improve_skill("jinyuan-gun"))
                me->improve_skill("jinyuan-gun", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/jinyuan-gun/qian", 1);
        me->add("gongxian", -800);

        return 1;
}

mixed ask_back()
{
    	object me, myenv;
    	me = this_player();

        if (find_object(query("startroom")) != environment())
                return "�ף����š�������⡭�㻹���Լ����Ű�ɡ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�����̵ģ�������ô��";

        command("nod");
	message_vision(HIW "�ų˷����һ������Ȼ������Х�����϶�ʱ����һ���������\n\n"
                       NOR + HIY "$N" HIY "һ�������˵��������������ؽ�����ȥ����\n\n", me);
        myenv = environment(me);
        me->move ("/d/heimuya/basket");
        me->start_call_out((: call_other, __FILE__, "up1", me :), 5);
        return 1;
}

void up1(object me)
{
    	tell_object(me, HIW "\n������ĵ�����������������Ķ��������³�ȥ��\n\n" NOR);
        me->start_call_out((: call_other, __FILE__, "up2", me :), 5);
}

void up2(object me)
{
    	tell_object(me, HIW "\n����ǰһ����һ������ɫ����������ǰ�����ǻԻ͡�\n\n" NOR);
        me->move("/d/heimuya/shanya3");
        message_vision(HIC "\n$N" HIC "�����������˺�ľ�¡�\n\n" NOR, me);
}
