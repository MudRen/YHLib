#include <ansi.h>
#include "riyue.h"

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;

mixed ask_skill1();
mixed ask_skill2();
mixed ask_skill3();
mixed ask_skill4();
mixed ask_skill5();

mixed  try_to_learn_xixingdafa();

void create()
{
        set_name("������", ({ "ren woxing", "ren", "woxing" }));
        set("nickname", HIW "��������" NOR);
        set("title", "������̽���");
        set("long", @LONG 
���������������ν��������С�ֻ����һ��
����������ѩ�ף����ް��Ѫɫ����üĿ���㣬
������ߣ�һͷ�ڷ���������һϮ������
LONG);
        set("gender", "����");
        set("class", "scholar");
        set("age", 65);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 40);
        set("int", 40);
        set("con", 40);
        set("dex", 40);
        
        set("max_qi", 7000);
        set("max_jing", 5000);
        set("neili", 9000);
        set("max_neili", 9000);
        set("jiali", 200);
        set("combat_exp", 4000000);
        set("score", 50000);

        set_skill("force", 340);
        set_skill("xixing-dafa", 340);
        set_skill("tianhuan-shenjue", 320);
        set_skill("riyue-xinfa", 320);
        set_skill("dodge", 320);
        set_skill("feiyan-zoubi", 320);
        set_skill("juechen-shenfa", 320);
        set_skill("strike", 340);
        set_skill("guzhuo-zhang", 340);
        set_skill("qingmang-zhang", 320);
        set_skill("hand", 320);
        set_skill("lansha-shou", 320);
        set_skill("cuff", 320);
        set_skill("zhenyu-quan", 320);
        set_skill("claw", 320);
        set_skill("poyue-zhao", 320);
        set_skill("parry", 320);
        set_skill("sword", 340);
        set_skill("yuanshi-jian", 340);
        set_skill("taishan-sword", 300);
        set_skill("hengshan-jian", 300);
        set_skill("hengshan-sword", 300);
        set_skill("huashan-sword", 300);
        set_skill("songshan-sword", 300);
        set_skill("blade", 280);
        set_skill("danding-dao", 280);
        set_skill("throwing", 280);
        set_skill("heixue-shenzhen", 280);
        set_skill("martial-cognize", 320);
        set_skill("literate", 320);

        map_skill("dodge", "juechen-shenfa");
        map_skill("force", "xixing-dafa");
        map_skill("strike", "guzhuo-zhang");
        map_skill("sword", "yuanshi-jian");
        map_skill("parry", "guzhuo-zhang");
        map_skill("hand", "lansha-shou");
        map_skill("cuff", "zhenyu-quan");
        map_skill("claw", "poyue-zhao");
        map_skill("blade", "danding-dao");
        map_skill("throwing", "heixue-shenzhen");

        prepare_skill("strike", "guzhuo-zhang");

        set("no_teach", ([
                "xixing-dafa"   : (: try_to_learn_xixingdafa :),
                "taishan-sword"  : "����Һú�ר�б����书���������ɵĽ���ѧ��������",
                "hengshan-jian"  : "����Һú�ר�б����书���������ɵĽ���ѧ��������",
                "hengshan-sword" : "����Һú�ר�б����书���������ɵĽ���ѧ��������",
                "huashan-sword"  : "����Һú�ר�б����书���������ɵĽ���ѧ��������",
                "songshan-sword" : "����Һú�ר�б����书���������ɵĽ���ѧ��������",
        ]));

        create_family("�������", 13, "����");

        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        set("inquiry", ([
                "��ع�Ԫ" : (: ask_skill1 :),
                "������ת" : (: ask_skill2 :),
                "������׾" : (: ask_skill3 :),
                "��������" : (: ask_skill4 :),
                "��豹���" : (: ask_skill5 :),
        ]));

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "sword.gui" :),
		(: perform_action, "sword.xuan" :),
                (: perform_action, "strike.zhuo" :),
                (: perform_action, "strike.yu" :),
                (: perform_action, "strike.zhen" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
		(: exert_function, "suck" :),
	}) );

        setup();
        carry_object("/d/heimuya/npc/obj/zaohong")->wear();
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("shen") > -80000)
        {
                command("sneer");
                command("say �Ϸ�ƽ����ʹ�޵ľ����������ļ��ʼ���֮ͽ��");
                return;
        }

        if (ob->query("combat_exp") < 500000)
        {
                command("say �����ڽ�������̫ǳ�������ȸ��漸λ����ѧϰ�ɡ�");
                return;
        }

	if (ob->query_int() < 34)
	{
		command("hmm");
		command("say ��������ô���ô����ҵ��书��");
		return;
	}

        if (ob->query_skill("tianhuan-shenjue", 1) < 150
           && ob->query_skill("riyue-xinfa", 1) < 150)
        {
                command("hmm");
                command("say ����������������ڹ���û�޺ã���ôѧϰ�ϳ���ѧ��");
                return;
        }

        command("nod2");
        command("say ������������ģ��Ա��������Ĺ����������ұ�����Ϊͽ��");
        command("say ���������һͳ������ǧ���ҵ����ȫ�������ˡ�");
        command("recruit " + ob->query("id"));
        return;
}

mixed try_to_learn_xixingdafa()
{
        object ob = this_player();

        if (ob->query("can_learn/xixing-dafa/ren"))
                return 0;

        if (ob->query_skill("force", 1) > 180)
        {
                command("say ���ʱ�Ĺ�������Ϊ��񣬽����Ҿʹ������Ǵ󷨡�");
	        command("whisper " + ob->query("id") + " ѹ���������ɵĿھ�"
                        "��%X&$&$%$$#$#���ɼǺ��ˡ�");
                ob->set("can_learn/xixing-dafa/ren", 1);
                return 0;
        }

        return "���ʱ����̫ǳ��ǿ�޴˹����߻���ħ��";
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/yuanshi-jian/gui"))
                return "��һ���Ҳ����Ѿ��̹�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "���ֲ�����������̵ģ�������ʲô�ң�";

        if (me->query_skill("yuanshi-jian", 1) < 1)
                return "����ԭʼ������ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 500)
                return "���ڽ���������Ϊ����������ʱ�����ܴ��㡣";

        if (me->query("shen") > -120000)
                return "�������Ĵ���������ѧ����������ʲô�ã�";

        if (me->query_skill("force") < 200)
                return "����ڹ����������ߣ��������������Ұɡ�";

        if (me->query_skill("yuanshi-jian", 1) < 140)
                return "���ԭʼ���������ò����ң��Լ���ȥ���������ɣ�";

        message_sort(HIY "\n$n" HIY "���˵�ͷ���漴�㽫$N" HIY "�������"
                     "���ڶ��Ե���ϸ˵���ã�$N" HIY "������ĵ�һЦ������"
                     "��������\n\n" NOR, me, this_object()); 

        command("nod2");
        command("say �ղ���˵��ȫ�Ǵ��еľ�Ҫ����Ҫ�����ˡ�");
        tell_object(me, HIC "��ѧ���ˡ���ع�Ԫ����\n" NOR);
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("yuanshi-jian"))
                me->improve_skill("yuanshi-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/yuanshi-jian/gui", 1);
        me->add("gongxian", -500);

        return 1;
}

mixed ask_skill2()
{
        object me;

        me = this_player();

        if (me->query("can_perform/yuanshi-jian/xuan"))
                return "��һ���Ҳ����Ѿ��̹�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "���ֲ�����������̵ģ�������ʲô�ң�";

        if (me->query_skill("yuanshi-jian", 1) < 1)
                return "����ԭʼ������ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 1400)
                return "���ڽ���������Ϊ����������ʱ�����ܴ��㡣";

        if (me->query("shen") > -130000)
                return "�������Ĵ���������ѧ����������ʲô�ã�";

        if (me->query_skill("force") < 260)
                return "����ڹ����������ߣ��������������Ұɡ�";

        if (me->query_skill("yuanshi-jian", 1) < 180)
                return "���ԭʼ���������ò����ң��Լ���ȥ���������ɣ�";

        message_sort(HIY "\n$n" HIY "΢΢һЦ���ӻ�������ȡ����һ������"
                     "��ָ������һ�ζ�$N" HIY "ϸ˵���ã�$N" HIY "һ����"
                     "һ�߲�ס�ص�ͷ��\n\n" NOR, me, this_object());

        command("nod");
        command("say ��ֻ���ס���Կ���������˻��ȡ���˸��ֱ�ɡ�");
        tell_object(me, HIC "��ѧ���ˡ�������ת����\n" NOR);
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("yuanshi-jian"))
                me->improve_skill("yuanshi-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/yuanshi-jian/xuan", 1);
        me->add("gongxian", -1400);

        return 1;
}

mixed ask_skill3()
{
        object me;

        me = this_player();

        if (me->query("can_perform/guzhuo-zhang/zhuo"))
                return "��һ���Ҳ����Ѿ��̹�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "���ֲ�����������̵ģ�������ʲô�ң�";

        if (me->query_skill("guzhuo-zhang", 1) < 1)
                return "������׾�Ʒ���ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 600)
                return "���ڽ���������Ϊ����������ʱ�����ܴ��㡣";

        if (me->query("shen") > -120000)
                return "�������Ĵ���������ѧ����������ʲô�ã�";

        if (me->query("max_neili") < 1800)
                return "�������̫���ô�����ϳ��书��";

        if (me->query_skill("force") < 220)
                return "����ڹ����������ߣ��������������Ұɡ�";

        if (me->query_skill("guzhuo-zhang", 1) < 150)
                return "��Ĺ�׾�Ʒ������ò����ң��Լ���ȥ���������ɣ�";

        message_sort(HIY "\n$n" HIY "��Цһ���������𻰣�ֻ�����ֻӳ�һ��"
                     "�����ް����ʽ���ԡ�����֪�⿴�Ʋ������һ�ƣ�������"
                     "��Χ��ɳ�����Ʒ��Х������ֱ�ε�$N" HIY "��������"
                     "���ۡ���ʽ֮�ɣ�ʵ��$N" HIY "ǰ��δ�š�\n\n" NOR, me,
                     this_object());

        command("nod");
        command("say ��������");
        tell_object(me, HIC "��ѧ���ˡ�������׾����\n" NOR);
        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("guzhuo-zhang"))
                me->improve_skill("guzhuo-zhang", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/guzhuo-zhang/zhuo", 1);
        me->add("gongxian", -600);

        return 1;
}

mixed ask_skill4()
{
        object me;

        me = this_player();

        if (me->query("can_perform/guzhuo-zhang/yu"))
                return "��һ���Ҳ����Ѿ��̹�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "���ֲ�����������̵ģ�������ʲô�ң�";

        if (me->query_skill("guzhuo-zhang", 1) < 1)
                return "������׾�Ʒ���ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 1200)
                return "���ڽ���������Ϊ����������ʱ�����ܴ��㡣";

        if (me->query("shen") > -150000)
                return "�������Ĵ���������ѧ����������ʲô�ã�";

        if (me->query("max_neili") < 2800)
                return "�������̫���ô�����ϳ��书��";

        if (me->query_skill("force") < 260)
                return "����ڹ����������ߣ��������������Ұɡ�";

        if (me->query_skill("guzhuo-zhang", 1) < 180)
                return "��Ĺ�׾�Ʒ������ò����ң��Լ���ȥ���������ɣ�";

        message_sort(HIY "\n$n" HIY "��Ц��������$N" HIY "�޵������벻����"
                     "���Ʒ���Ȼ�Ѵ�������裬�����Ϸ����������кη�����"
                     "$n" HIY "�漴�ڿ����ƣ���������ʾ������\n\n" NOR, me,
                     this_object());

        command("haha");
        command("say ֻ������������������д����Ʊ��������ˡ�");
        tell_object(me, HIC "��ѧ���ˡ��������ޡ���\n" NOR);
        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("guzhuo-zhang"))
                me->improve_skill("guzhuo-zhang", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/guzhuo-zhang/yu", 1);
        me->add("gongxian", -1200);

        return 1;
}

mixed ask_skill5()
{
        object me;

        me = this_player();

        if (me->query("can_perform/guzhuo-zhang/zhen"))
                return "��һ���Ҳ����Ѿ��̹�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "���ֲ�����������̵ģ�������ʲô�ң�";

        if (me->query_skill("guzhuo-zhang", 1) < 1)
                return "������׾�Ʒ���ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 2200)
                return "���ڽ���������Ϊ����������ʱ�����ܴ��㡣";

        if (me->query("shen") > -200000)
                return "�������Ĵ���������ѧ����������ʲô�ã�";

        if (! me->query("can_perform/guzhuo-zhang/zhuo")
           || ! me->query("can_perform/guzhuo-zhang/yu"))
                return "����ǰ���ж�δ���ɣ���ôѧ�����һ�У�";

        if (me->query("max_neili") < 3600)
                return "�������̫���ô�����ϳ��书��";

        if (me->query_skill("force") < 300)
                return "����ڹ����������ߣ��������������Ұɡ�";

        if (me->query_skill("guzhuo-zhang", 1) < 220)
                return "��Ĺ�׾�Ʒ������ò����ң��Լ���ȥ���������ɣ�";

        message_sort(HIY "\n$n" HIY "��$N" HIY "΢΢���˵�ͷ������˵����"
                     "�����������׹�׾�Ʒ��Ѿ������൱�����ˣ������Ϸ��"
                     "�������С���˵��㽫$N" HIY "������ǰϸ˵���ã���Ȼ"
                     "��ֻ��$n" HIY "��Ȼ̽�����֣�ƽ�ƶ�����$N" HIY "ֻ"
                     "���Ʒ����ȣ�����֮������ʱ�ؿ�һ�����ƣ����ܵ�˵��"
                     "��������\n\n" NOR, me, this_object());

        command("haha");
        command("say ���к�һ�������У�����������");
        tell_object(me, HIC "��ѧ���ˡ���豹��桹��\n" NOR);
        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("guzhuo-zhang"))
                me->improve_skill("guzhuo-zhang", 1500000);
        if (me->can_improve_skill("guzhuo-zhang"))
                me->improve_skill("guzhuo-zhang", 1500000);
        if (me->can_improve_skill("guzhuo-zhang"))
                me->improve_skill("guzhuo-zhang", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/guzhuo-zhang/zhen", 1);
        me->add("gongxian", -2200);

        return 1;
}