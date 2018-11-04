#include <ansi.h>
#include "taohua.h"

#define YUXIAO    "/clone/lonely/yuxiao"
#define TAOHUA    "/clone/lonely/book/taohua"
#define XIAOPU    "/clone/lonely/book/xiaopu"
#define XUANFENG  "/clone/lonely/book/xuanfengtui"

inherit NPC;
inherit F_MASTER;
inherit F_GUARDER;
inherit F_QUESTER;

void   consider();

mixed  ask_leave();
mixed  ask_book1();
mixed  ask_book2();
mixed  ask_book3();
mixed  ask_book4();
mixed  ask_yuxiao();

mixed  ask_skill1();
mixed  ask_skill2();
mixed  ask_skill3();
mixed  ask_skill4();
mixed  ask_skill5();
mixed  ask_skill6();
mixed  ask_skill7();
mixed  ask_skill8();
mixed  ask_skill9();
mixed  ask_skill10();

mixed  try_to_learn_bibo();
mixed  try_to_learn_count();
mixed  try_to_learn_tanzhi();

// ������pfm
mixed ask_zhi();
mixed ask_shou();
mixed ask_zhang();

void create()
{
        object ob;
        set_name("��ҩʦ", ({"huang yaoshi", "huang", "yaoshi"}));
        set("title", "�����һ�������");
        set("nickname", HIC "��а" NOR );
        set("gender", "����");
        set("age", 42);
        set("long", "�������һ����������ºö�ȫ�ɼ��ģ���˱�\n"
                    "�˳�������а����\n");
        set("attitude", "peaceful");
        set("class", "scholar");
        set("str", 40);
        set("int", 40);
        set("con", 40);
        set("dex", 40);
        set("qi", 7000);
        set("max_qi", 7000);
        set("jing", 5000);
        set("max_jing", 5000);
        set("neili", 7000);
        set("max_neili", 7000);
        set("jiali", 200);
        set("combat_exp", 4000000);

        set_skill("force", 340);
        set_skill("bibo-shengong", 340);
        set_skill("luoying-xinfa", 320);
        set_skill("hand", 320);
        set_skill("finger", 340);
        set_skill("canglang-zhi", 320);
        set_skill("tanzhi-shentong", 340);
        set_skill("unarmed", 320);
        set_skill("strike", 320);
        set_skill("pikong-zhang", 320);
        set_skill("luoying-shenzhang", 320);
        set_skill("xuanfeng-tui", 320);
        set_skill("dodge", 320);
        set_skill("anying-fuxiang", 320);
        set_skill("parry", 320);
        set_skill("sword", 320);
        set_skill("throwing", 340);
        set_skill("luoying-shenjian", 320);
        set_skill("yuxiao-jian", 320);
        set_skill("lanhua-shou", 320);
        set_skill("qimen-wuxing", 350);
        set_skill("count", 350);
        set_skill("jingluo-xue", 350);
        set_skill("mathematics", 350);
        set_skill("literate", 350);
        set_skill("chuixiao-jifa", 350);
        set_skill("bihai-chaosheng", 350);
        set_skill("taohua-yuan", 350);
        set_skill("drawing", 350);
        set_skill("chess", 350);
        set_skill("calligraphy", 350);
        set_skill("medical", 350);
        set_skill("taohua-yaoli", 350);
        set_skill("martial-cognize", 320);

        map_skill("force", "bibo-shengong");
        map_skill("finger", "tanzhi-shentong");
        map_skill("hand", "lanhua-shou");
        map_skill("unarmed", "xuanfeng-tui");
        map_skill("strike", "luoying-shenzhang");
        map_skill("dodge", "anying-fuxiang");
        map_skill("parry", "tanzhi-shentong");
        map_skill("sword", "yuxiao-jian");
        map_skill("chuixiao-jifa", "bihai-chaosheng");
        map_skill("throwing", "tanzhi-shentong");
        map_skill("medical", "taohua-yaoli");

        prepare_skill("finger" , "tanzhi-shentong");

        set("no_teach", ([
                "count"           : (: try_to_learn_count :),
                "bibo-shengong"   : (: try_to_learn_bibo :),
                "tanzhi-shentong" : (: try_to_learn_tanzhi :),
        ]));

        set("inquiry", ([
                "�뵺"       : (: ask_leave :),
                "�һ�ҩ��"   : (: ask_book1 :),
                "����"       : (: ask_book2 :),
                "����ɨҶ��" : (: ask_book3 :),
                "��ͼ"       : (: ask_book4 :),
                "����"       : (: ask_book4 :),
                "����"       : (: ask_yuxiao :),
                "������ת"   : (: ask_skill1 :),
                "������Ѩ"   : (: ask_skill2 :),
                "Ӱ��ɻ�"   : (: ask_skill3 :),
                "��������"   : (: ask_skill4 :),
                "����鳤"   : (: ask_skill5 :),
                "�̺�����"   : (: ask_skill6 :),
                "������"     : (: ask_skill7 :),
                "Х�׺�"     : (: ask_skill8 :),
                "�ƾ���"     : (: ask_skill9 :),
                "תǬ��"     : (: ask_skill10 :),
                "��������"   : "������ȥ�÷�Ĭ�����ɡ�",
                "���Ǵ���"   : "������ȥ��½�˷����ɡ�",
                "������"   : "������ȥ��½�˷����ɡ�",
                "�沨����"   : "������ȥ����������ɡ�",
                "����"       : "���ֱ����Ů���Ĺ�����",
                "�����澭"   : "������ܰ���ȡ���澭����һ������л�㡣",
                "������"   : "�����񹦻ֺ������˸����湦��",
                "������ָ"   : (: ask_zhi :),
                "��������"   : (: ask_zhang :),
                "��������"   : (: ask_shou :),
                "������"     : "������Ѩ�֡�������ϧ�Ҽ������Ӷ��㲻�óɲţ�",
                "��ָ��ͨ"   : "��������һ����վ�Ȼ���˿��Լ̳У�",
                "��������"   : "�����������ˣ�����ܹ�����⽣����",
                "�̲���"   : "���������һ������ڹ��ε���������ϧ��",
                "�Ż���¶��" : "����������Ƶý�����ú�ѧѧ�һ�ҩ���Ժ��Լ��ưɡ�",
                "�޳���"     : "���š�����ѧͨ���һ�ҩ��İ���Լ������ưɡ�",
        ]));

        create_family("�һ���", 1, "����");

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "sword.bihai" :),
		(: perform_action, "sword.qing" :),
		(: perform_action, "sword.tian" :),
		(: perform_action, "finger.ding" :),
		(: perform_action, "finger.xiao" :),
		(: perform_action, "finger.po" :),
		(: perform_action, "finger.zhuan" :),
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
	}));
        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        setup();

        if (clonep())
        {
                ob = find_object(YUXIAO);
                if (! ob) ob = load_object(YUXIAO);
                if (! environment(ob))
                {
                        ob->move(this_object());
                        set_temp("handing", ob);
                } else
                {
                        set_temp("handing", carry_object("/d/taohua/obj/huaban"));
                }
        }
        carry_object("/d/taohua/obj/bupao")->wear();
}

void attempt_apprentice(object ob)
{
        string master;
        string *app = ({ "��Ĭ��", "½�˷�", "�����" });

        if (! permit_recruit(ob))
                return;

        if (ob->query_int() < 25)
        {
                command("say �Ҳ������ʲ�ĵ��ӣ�����ذɣ�");
		return;
        }

        if ((int)ob->query ("shen") < -10000
           || (int)ob->query ("shen") > 10000)
        {
                command("say �Ҳ����������򽻵�������ذɣ�");
		return;
	}

        if (ob->query("combat_exp") < 400000)
        {
                if (stringp(master = ob->query_temp("taohua/master")))
                {
                        command("say ���������" + master + "ѧ��������ô���£�");
                        return;
                }

                if (ob->query("family/family_name") == "�һ���" &&
                    ob->query("family/master_name") != "��ҩʦ")
                {
                        command("say ��úø�" + ob->query("family/master_name") +
                                "ѧ�գ�ˮƽ�����Ϸ���Ȼ�����Ե㲦�㡣");
                        return;
                }

                master = app[random(sizeof(app))];
                
                command("say �š����㳤;���������ʦ���Ϸ���������һ�����");
                command("say ��������ѧ����ɾ����ޣ������ȸ��ҵ���" + master + "ѧϰ�ɡ�");
                ob->set_temp("taohua/master", master);
                ob->set("family/family_name", "�һ���");
                return;
        }
        command("say �ܺã��ܺá�");
        command("recruit " + ob->query("id"));
}

mixed try_to_learn_count()
{
        object ob = this_player();

        if (ob->query("can_learn/huang/count"))
                return 0;

        if (ob->query_skill("mathematics", 1) >= 200)
        {
                command("nod2");
                command("say �����������Ҳ���м��⣬�����Ϸ�ͽ�"
                        "��Щ�������Ե�֪ʶ��");
                ob->set("can_learn/huang/count", 1);
                return 0;
        }
        return "���������Ҳ����״��ڡ�";
}

mixed try_to_learn_bibo()
{
        object ob = this_player();

        if (ob->query("can_learn/huang/bibo-shengong"))
                return 0;

        if (ob->query_skill("bihai-chaosheng", 1) >= 120
	   && ob->query_skill("chuixiao-jifa", 1) >= 120)
        {
                command("sigh");
                command("say �벻����������Ȼ�Ѵ�˾��磬�����Ϸ�"
                        "�ʹ���̲��񹦰ɡ�");
                ob->set("can_learn/huang/bibo-shengong", 1);
                return 0;
        }
        return "�����������ˣ���̲��񹦲����ʺ��㡣";
}

mixed try_to_learn_tanzhi()
{
        object ob = this_player();

        if (ob->query("can_learn/huang/tanzhi-shentong"))
                return 0;

        if (ob->query_skill("qimen-wuxing", 1) >= 120
	   && ob->query_skill("jingluo-xue", 1) >= 120
	   && ob->query_skill("finger", 1) >= 120
	   && ob->query_skill("throwing", 1) >= 120)
        {
                command("nod2");
                command("say �������书������һ���ĸ����������Ϸ�"
                        "�ʹ�����׾�����");
                ob->set("can_learn/huang/tanzhi-shentong", 1);
                return 0;
        }

        return "���ʱ����̫ǳ��������ᵯָ��ͨ��";
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/luoying-shenzhang/zhuan"))
                return "��һ���Ҳ����Ѿ��̹������𣿻�����ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�㲻�������һ������ˣ������Ϸ���书�к���ͼ��";

        if (me->query_skill("luoying-shenzhang", 1) < 1)
                return "������Ӣ���ƶ�ûѧ��������ʲô�ң�";

        if (me->query("gongxian") < 350)
                return "�������һ���������Ϊ�������Ϸ���ʱ�����ܴ��㡣";

        if (me->query_skill("force") < 180)
                return "����ڹ����������ߣ������������ɡ�";

        if (me->query_skill("qimen-wuxing", 1) < 120)
                return "����������е��о����������л�ѧ���ᡣ";

        if (me->query_skill("luoying-shenzhang", 1) < 120)
                return "�ߣ��������Ӣ�����������������ң�";

        message_sort(HIY "\n$n" HIY "������$N" HIY "һ�ۣ����ֹ���һ�ơ�$N" HIY
                     "������ƽƽ���������棬��֪�������ֵ���һ˲��ŷ���$n" HIY
                     "��������ƺӾ��̰���ӿ���룬$N" HIY "��ʱ��Ҳ�ѳֲ�ס����"
                     "���������ý�����ת����Ȧ���ò����ײ�ͣ��������\n\n" NOR,
                     me, this_object()); 

        command("say ���ˣ�����ȥ�ɡ�");
        tell_object(me, HIC "��ѧ���ˡ�������ת����\n" NOR);
        if (me->can_improve_skill("qimen-wuxing"))
                me->improve_skill("qimen-wuxing", 1500000);
        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("luoying-shenzhang"))
                me->improve_skill("luoying-shenzhang", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/luoying-shenzhang/zhuan", 1);
        me->add("gongxian", -350);

        return 1;
}

mixed ask_skill2()
{
        object me;

        me = this_player();

        if (me->query("can_perform/lanhua-shou/fu"))
                return "�Լ���ȥ��������ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�㲻�������һ������ˣ������Ϸ���书�к���ͼ��";

        if (me->query_skill("lanhua-shou", 1) < 1)
                return "����������Ѩ�ֶ�ûѧ��������ʲô�ң�";

        if (me->query("gongxian") < 300)
                return "�������һ���������Ϊ�������Ϸ���ʱ�����ܴ��㡣";

        if (me->query_skill("force") < 160)
                return "����ڹ����������ߣ������������ɡ�";

        if (me->query_skill("jingluo-xue", 1) < 120)
                return "��������ѧ��ûѧͨ����ô����Ѩ����";

        if (me->query_skill("lanhua-shou", 1) < 120)
                return "�����������Ѩ���������������Ϸ�";

        message_sort(HIY "\n$n" HIY "΢΢���˵�ͷ���������������ָ����ת��һ��"
                     "ʢ������������׼$N" HIY "�ļ���Ѩ��������¡�\n\n" NOR,
                     me, this_object()); 

        command("say ������ô��");
        tell_object(me, HIC "��ѧ���ˡ�������Ѩ����\n" NOR);
        if (me->can_improve_skill("jingluo-xue"))
                me->improve_skill("jingluo-xue", 1500000);
        if (me->can_improve_skill("hand"))
                me->improve_skill("hand", 1500000);
        if (me->can_improve_skill("lanhua-shou"))
                me->improve_skill("lanhua-shou", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/lanhua-shou/fu", 1);
        me->add("gongxian", -300);

        return 1;
}

mixed ask_skill3()
{
        object me;

        me = this_player();

        if (me->query("can_perform/lanhua-shou/fei"))
                return "�������Լ���ȥ���ɡ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�㲻�������һ������ˣ������Ϸ���书�к���ͼ��";

        if (me->query_skill("lanhua-shou", 1) < 1)
                return "����������Ѩ�ֶ�ûѧ��������ʲô�ң�";

        if (me->query("gongxian") < 400)
                return "�������һ���������Ϊ�������Ϸ���ʱ�����ܴ��㡣";

        if (me->query_skill("force") < 200)
                return "����ڹ����������ߣ������������ɡ�";

        if (me->query_skill("lanhua-shou", 1) < 140)
                return "�����������Ѩ���������������Ϸ�";

        message_sort(HIY "\n$n" HIY "һ����̾�����ֽ�$N" HIY "���������ԣ�����"
                     "��$N" HIY "����ϸ˵���á�$N" HIY "һ����һ�ߵ�ͷ��������"
                     "$n" HIY "�Ľ̵���������\n\n" NOR, me, this_object()); 

        command("say �������Լ���ȥ���ɡ�");
        tell_object(me, HIC "��ѧ���ˡ�Ӱ��ɻ�����\n" NOR);
        if (me->can_improve_skill("hand"))
                me->improve_skill("hand", 1500000);
        if (me->can_improve_skill("lanhua-shou"))
                me->improve_skill("lanhua-shou", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/lanhua-shou/fei", 1);
        me->add("gongxian", -400);

        return 1;
}

mixed ask_skill4()
{
        object me;

        me = this_player();

        if (me->query("can_perform/yuxiao-jian/tian"))
                return "��һ���Ҳ����Ѿ��̹������𣿻�����ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�㲻�������һ������ˣ������Ϸ���书�к���ͼ��";

        if (me->query_skill("yuxiao-jian", 1) < 1)
                return "�������｣����ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 350)
                return "�������һ���������Ϊ�������Ϸ���ʱ�����ܴ��㡣";

        if (me->query_skill("bibo-shengong", 1) < 120)
                return "��̲��񹦵���Ϊ������ѧ������һ�С�";

        if (me->query_skill("yuxiao-jian", 1) < 120)
                return "������｣���������������������������ҡ�";

        message_sort(HIY "\n$n" HIY "΢΢���˵�ͷ�����ֽ�$N" HIY "�е���ǰ����"
                     "$N" HIY "���������ֹ���Щ����$N" HIY "���˰��죬ͻȻ�䲻"
                     "�ɻ��ĵ�һЦ��������������\n\n" NOR, me, this_object());

        command("nod2");
        command("say ����ȥ���ɡ�");
        tell_object(me, HIC "��ѧ���ˡ�������������\n" NOR);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("yuxiao-jian"))
                me->improve_skill("yuxiao-jian", 1500000);
        if (me->can_improve_skill("bibo-shengong"))
                me->improve_skill("bibo-shengong", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/yuxiao-jian/tian", 1);
        me->add("gongxian", -350);

        return 1;
}

mixed ask_skill5()
{
        object me;

        me = this_player();

        if (me->query("can_perform/yuxiao-jian/qing"))
                return "��һ���Ҳ����Ѿ��̹������𣿻�����ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�㲻�������һ������ˣ������Ϸ���书�к���ͼ��";

        if (me->query_skill("yuxiao-jian", 1) < 1)
                return "�������｣����ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 400)
                return "�������һ���������Ϊ�������Ϸ���ʱ�����ܴ��㡣";

        if (me->query_skill("force") < 200)
                return "����ڹ����������ߣ������������ɡ�";

        if (me->query_skill("yuxiao-jian", 1) < 150)
                return "������㱾�£���������｣���������������Ұɣ�";

        message_sort(HIY "\n$n" HIY "��ͷ���죬������˼�����ִ���$N" HIY "�ļ�"
                     "ͷ��$N" HIY "��Ȼ��������ԴԴ���ţ����ɴ󾪣�\n\n" NOR,
                     me, this_object()); 

        command("sigh");
        command("say �㶮��ô��");
        tell_object(me, HIC "��ѧ���ˡ�����鳤����\n" NOR);
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("yuxiao-jian"))
                me->improve_skill("yuxiao-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/yuxiao-jian/qing", 1);
        me->add("gongxian", -400);

        return 1;
}

mixed ask_skill6()
{
        object me;

        me = this_player();

        if (me->query("can_perform/yuxiao-jian/bihai"))
                return "��һ���Ҳ����Ѿ��̹������𣿻�����ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�㲻�������һ������ˣ������Ϸ���书�к���ͼ��";

        if (me->query_skill("yuxiao-jian", 1) < 1
	   && me->query_skill("bibo-shengong", 1) < 1
	   && me->query_skill("bihai-chaosheng", 1) < 1)
                return "�����｣�����̲��񹦡��̺�������һ����ûѧ����ʲô�ң�";

        if (me->query("gongxian") < 1000)
                return "�������һ���������Ϊ�������Ϸ���ʱ�����ܴ��㡣";

        if (me->query_skill("bibo-shengong", 1) < 180)
                return "��̲��񹦵���Ϊ������ѧ������һ�С�";

        if (me->query_skill("yuxiao-jian", 1) < 180)
                return "������｣���������������������������ҡ�";

        if (me->query_skill("bihai-chaosheng", 1) < 180)
                return "��ı̺���������������";

        message_sort(HIY "\n$n" HIY "�����𻰣����ָ������ֻ�������������ٻ�"
                     "�񣬷��˼����������������Ʈ��������͵Ķ���������ֻ����"
                     "����������Ʈ����������ת������һŮ��һ���̾Ϣ��һ�������"
                     "������һ���ȴ�������´�������л������������������������"
                     "�����������޲���Զ����ˮ�����ƽ����������죬��������ӿ"
                     "��������ɽ������ˮ����Ծ�����������Ϸ�ХŸ�ɣ��ټ���ˮ����"
                     "�֣�ȺħŪ����������ɽƮ���������Ⱥ���У��������֮���¡�"
                     "ʱ�����ȴ��������������ϸ�������������ţ�������󺣳���"
                     "��ˮƽ�羵һ�㣬������ȴ���ǰ����ļ�����ӿ���ȡ�ֱ��$n" HIY
                     "���ױ̺����������꣬ȴ����$N" HIY "����������������֮�У���"
                     "ȫ�޷��԰Ρ�\n\n" NOR, me, this_object()); 

        command("nod");
        command("say ����ȥ���ɡ�");
        tell_object(me, HIC "��ѧ���ˡ��̺������������\n" NOR);

        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("chuixiao-jifa"))
                me->improve_skill("chuixiao-jifa", 1500000);
        if (me->can_improve_skill("yuxiao-jian"))
                me->improve_skill("yuxiao-jian", 1500000);
        if (me->can_improve_skill("bibo-shengong"))
                me->improve_skill("bibo-shengong", 1500000);
        if (me->can_improve_skill("bihai-chaosheng"))
                me->improve_skill("bihai-chaosheng", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/yuxiao-jian/bihai", 1);
        me->add("gongxian", -1000);

        return 1;
}

mixed ask_skill7()
{
        object me;

        me = this_player();

        if (me->query("can_perform/tanzhi-shentong/ding"))
                return "��һ���Ҳ����Ѿ��̹������𣿻�����ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�㲻�������һ������ˣ������Ϸ���书�к���ͼ��";

        if (me->query_skill("tanzhi-shentong", 1) < 1)
                return "������ָ��ͨ��ûѧ��Ϲ����ʲô��";

        if (me->query("gongxian") < 450)
                return "�������һ���������Ϊ�������Ϸ���ʱ�����ܴ��㡣";

        if (me->query_skill("force") < 180)
                return "����ڹ����������ߣ������������ɡ�";

        if (me->query_skill("jingluo-xue", 1) < 120)
                return "������һ������ͨ������ѧ������ȥ���������ɡ�";

        if (me->query_skill("tanzhi-shentong", 1) < 120)
                return "��ĵ�ָ��ͨ��򻹲����������������������ҡ�";

        message_sort(HIY "\n$n" HIY "ת��ͷ����$N" HIY "һ�ۣ������𻰣�ֻ����"
                     "�������ָ����ָ�ᵯ����ʱֻ����쬡���һ����һ����������"
                     "���������$n" HIY "ָ���������$N" HIY "�����ȥ��$N" HIY
                     "�پ�в��һ�飬�ѱ�$n" HIY "��ָ�����У�ȫ����������������"
                     "������\n\n" NOR, me, this_object()); 

        command("say ��ʽ������ˣ���վ��������ĥһ�°ɡ�");
        tell_object(me, HIC "��ѧ���ˡ������ء���\n" NOR);
        if (me->can_improve_skill("jingluo-xue"))
                me->improve_skill("jingluo-xue", 1500000);
        if (me->can_improve_skill("finger"))
                me->improve_skill("finger", 1500000);
        if (me->can_improve_skill("tanzhi-shentong"))
                me->improve_skill("tanzhi-shentong", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/tanzhi-shentong/ding", 1);
        me->add("gongxian", -450);
        me->start_busy(15);

        return 1;
}

mixed ask_skill8()
{
        object me;

        me = this_player();

        if (me->query("can_perform/tanzhi-shentong/xiao"))
                return "��һ���Ҳ����Ѿ��̹������𣿻�����ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�㲻�������һ������ˣ������Ϸ���书�к���ͼ��";

        if (me->query_skill("tanzhi-shentong", 1) < 1)
                return "������ָ��ͨ��ûѧ��Ϲ����ʲô��";

        if (me->query("gongxian") < 800)
                return "�������һ���������Ϊ�������Ϸ���ʱ�����ܴ��㡣";

        if (me->query_skill("force") < 280)
                return "����ڹ����������ߣ������������ɡ�";

        if (me->query("max_neili") < 3000)
                return "���������Ϊ̫��������ߵ������ɡ�";

        if (me->query_skill("jingluo-xue", 1) < 200)
                return "������һ������ͨ������ѧ������ȥ���������ɡ�";

        if (me->query_skill("tanzhi-shentong", 1) < 200)
                return "��ĵ�ָ��ͨ��򻹲����������������������ҡ�";

        message_sort(HIY "\n$n" HIY "һ����̾�����ֽ�$N" HIY "���������ԣ�����"
                     "��$N" HIY "����ϸ˵���á�$N" HIY "һ����һ�ߵ�ͷ��������"
                     "$n" HIY "�Ľ̵���������\n\n" NOR, me, this_object()); 

        command("nod2");
        command("say ���š����Լ���ȥ�ɡ�");
        tell_object(me, HIC "��ѧ���ˡ�Х�׺�����\n" NOR);
        if (me->can_improve_skill("jingluo-xue"))
                me->improve_skill("jingluo-xue", 1500000);
        if (me->can_improve_skill("finger"))
                me->improve_skill("finger", 1500000);
        if (me->can_improve_skill("tanzhi-shentong"))
                me->improve_skill("tanzhi-shentong", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/tanzhi-shentong/xiao", 1);
        me->add("gongxian", -800);

        return 1;
}

mixed ask_skill9()
{
        object me;

        me = this_player();

        if (me->query("can_perform/tanzhi-shentong/po"))
                return "��һ���Ҳ����Ѿ��̹������𣿻�����ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�㲻�������һ������ˣ������Ϸ���书�к���ͼ��";

        if (me->query_skill("tanzhi-shentong", 1) < 1)
                return "������ָ��ͨ��ûѧ��Ϲ����ʲô��";

        if (me->query("gongxian") < 1300)
                return "�������һ���������Ϊ�������Ϸ���ʱ�����ܴ��㡣";

        if (me->query_skill("force") < 250)
                return "����ڹ����������ߣ������������ɡ�";

        if (me->query("max_neili") < 2500)
                return "���������Ϊ̫��������ߵ������ɡ�";

        if (me->query_skill("throwing", 1) < 180)
                return "��İ������û�������죬��ȥ���������ɡ�";

        if (me->query_skill("tanzhi-shentong", 1) < 180)
                return "��ĵ�ָ��ͨ��򻹲����������������������ҡ�";

        message_sort(HIY "\n$n" HIY "΢΢һЦ������Ҳ���������ִ������һ���"
                     "������һƬ���꣬$N" HIY "�������ƣ������ƿ�����������Ƭ"
                     "��������$n" HIY "ָ�⼲����������ʱֻ������һ������û��"
                     "$N" HIY "��ǰ����ʯש�ڣ�ʯ�������һ��С�ס�\n\n" NOR,
                     me, this_object()); 

        command("haha");
        tell_object(me, HIC "��ѧ���ˡ��ƾ��򡹡�\n" NOR);
        if (me->can_improve_skill("throwing"))
                me->improve_skill("throwing", 1500000);
        if (me->can_improve_skill("throwing"))
                me->improve_skill("throwing", 1500000);
        if (me->can_improve_skill("tanzhi-shentong"))
                me->improve_skill("tanzhi-shentong", 1500000);
        if (me->can_improve_skill("tanzhi-shentong"))
                me->improve_skill("tanzhi-shentong", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/tanzhi-shentong/po", 1);
        me->add("gongxian", -1300);

        return 1;
}

mixed ask_skill10()
{
        object me;

        me = this_player();

        if (me->query("can_perform/tanzhi-shentong/zhuan"))
                return "��һ���Ҳ����Ѿ��̹������𣿻�����ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�㲻�������һ������ˣ������Ϸ���书�к���ͼ��";

        if (me->query_skill("tanzhi-shentong", 1) < 1)
                return "������ָ��ͨ��ûѧ��Ϲ����ʲô��";

        if (me->query("gongxian") < 2200)
                return "�������һ���������Ϊ�������Ϸ���ʱ�����ܴ��㡣";

        if (me->query_skill("force") < 300)
                return "����ڹ����������ߣ������������ɡ�";

        if (me->query("max_neili") < 3500)
                return "���������Ϊ̫��������ߵ������ɡ�";

        if (me->query_skill("qimen-wuxing", 1) < 200)
                return "����������е��о����������л�ѧ���ᡣ";

        if (me->query_skill("tanzhi-shentong", 1) < 220)
                return "��ĵ�ָ��ͨ��򻹲����������������������ҡ�";

        message_sort(HIY "\n$n" HIY "������$N" HIY "���죬���������벻�����һ�"
                     "����Ȼ����������˲ţ�����պ�̳��Ϸ��²�����Ī���ˡ���"
                     "$n" HIY "˵�����һЦ����$N" HIY "�������ԣ�����ϸ˵����"
                     "���ã�ȫ��$N" HIY "ƽ����δ����ľ��磬$N" HIY "һ����һ"
                     "�ߵ�ͷ��������$n" HIY "�Ľ̵���������\n\n" NOR,
                     me, this_object()); 

        command("haha");
        command("say �ܴ��ڵ��Ҷ��Ѵ����ˣ��պ���Լ�Ŭ���ɡ�");
        tell_object(me, HIC "��ѧ���ˡ�תǬ������\n" NOR);
        if (me->can_improve_skill("qimen-wuxing"))
                me->improve_skill("qimen-wuxing", 1500000);
        if (me->can_improve_skill("qimen-wuxing"))
                me->improve_skill("qimen-wuxing", 1500000);
        if (me->can_improve_skill("qimen-wuxing"))
                me->improve_skill("qimen-wuxing", 1500000);
        if (me->can_improve_skill("finger"))
                me->improve_skill("finger", 1500000);
        if (me->can_improve_skill("finger"))
                me->improve_skill("finger", 1500000);
        if (me->can_improve_skill("finger"))
                me->improve_skill("finger", 1500000);
        if (me->can_improve_skill("tanzhi-shentong"))
                me->improve_skill("tanzhi-shentong", 1500000);
        if (me->can_improve_skill("tanzhi-shentong"))
                me->improve_skill("tanzhi-shentong", 1500000);
        if (me->can_improve_skill("tanzhi-shentong"))
                me->improve_skill("tanzhi-shentong", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/tanzhi-shentong/zhuan", 1);
        me->add("gongxian", -2200);

        return 1;
}

mixed ask_leave()
{
        object me;

        me = this_player();
        if (me->query("family/family_name") == "�һ���")
        {
                message_vision(CYN "$N" CYN "��$n" CYN "ŭ�������Ȼ���һ���"
                               "���£��һ�������㲻�ã�Ҫ�뵺�Լ��ߵ�����ȥ"
                               "��\n" NOR, this_object(), me);
                return 1;
        }

        command("hmm");
        message_vision(HIW "\n$N" HIW "���һ�������������������ͣ���$n" HIW
                       "���˳�ȥ��\n\n" NOR, this_object(), me);
        me->move("/d/taohua/haitan");
        message_vision(HIW "\n$N" HIW "�������������˺��ߡ�\n\n" NOR, me);
        return 1;
}

mixed ask_book1()
{
        object me;
        object ob;
        object owner;

        me = this_player();

        if (me->query("family/family_name") != "�һ���")
                return "���ҹ�����";

        if (me->query("family/master_id") != query("id"))
                return "ֻ���Ϸ�ĵ��Ӳ��������顣";

        if ((int)me->query_skill("taohua-yaoli", 1) < 60)
                return "����һ�ҩ����˽�̫ǳ�����������������˵��";

        ob = find_object(TAOHUA);
        if (! ob) ob = load_object(TAOHUA);
        owner = environment(ob);
        while (owner)
        {
                if (owner->is_character() || ! environment(owner))
                        break;
                owner = environment(owner);
        }

        if (owner == me)
                return "�Ǳ�ҩ�������������ڿ���";

        if (objectp(owner) && owner != this_object())
        {
                if (! owner->is_character())
                        return "���š��һ�ҩ�����ڲ��������";

                if (owner->query("family/family_name") == "�һ���")
                        return "����������ʱ����ͬ��" + owner->query("name") +
                               "�ڿ�����Ҫ�þ�ȥ�����ɡ�";
                else
                        return "�һ�ҩ������������" + owner->query("name") +
                               "���У���ȥ�������ذɡ�";
        }
        ob->move(this_object());
        command("say �Ȿ�һ�ҩ�������ȥ���ɣ���Ҫ�����ж���");
        command("give taohua yaoli to " + me->query("id"));
        return 1;
}

mixed ask_book2()
{
        object me;
        object ob;
        object owner;

        me = this_player();

        if (me->query("family/family_name") != "�һ���")
                return "���ҹ�����";

        if (me->query("family/master_id") != query("id"))
                return "ֻ���Ϸ�ĵ��Ӳ��������顣";

        if ((int)me->query_skill("chuixiao-jifa", 1) >= 150)
                return "����＼����˵ز��������׶������޶�������";

        ob = find_object(XIAOPU);
        if (! ob) ob = load_object(XIAOPU);
        owner = environment(ob);
        while (owner)
        {
                if (owner->is_character() || ! environment(owner))
                        break;
                owner = environment(owner);
        }

        if (owner == me)
                return "�Ǳ����ײ������������ڿ���";

        if (objectp(owner) && owner != this_object())
        {
                if (! owner->is_character())
                        return "�ҵ������Ѿ����ȥ�ˡ�";

                if (owner->query("family/family_name") == "�һ���")
                        return "����������ʱ����ͬ��" + owner->query("name") +
                               "�ڿ�����Ҫ�þ�ȥ�����ɡ�";
                else
                        return "�Ϸ����������������" + owner->query("name") +
                               "���У���ȥ�������ذɡ�";
        }
        ob->move(this_object());
        command("say �Ȿ���������ȥ���ɡ�");
        command("give xiao pu to " + me->query("id"));
        return 1;
}

mixed ask_book3()
{
        object me;
        object ob;
        object owner;

        me = this_player();

        if (me->query("family/family_name") != "�һ���")
                return "���ҹ�����";

        if ((int)me->query("combat_exp") < 100000)
                return "�����ڵľ���̫�ͣ������ȶ�������������";

        if ((int)me->query_skill("xuanfeng-tui", 1) >= 120)
                return "������ɨҶ�ȵ���Ϊ�Ѳ��ͣ������Լ�����ϰ�ɡ�";

        ob = find_object(XUANFENG);
        if (! ob) ob = load_object(XUANFENG);
        owner = environment(ob);
        while (owner)
        {
                if (owner->is_character() || ! environment(owner))
                        break;
                owner = environment(owner);
        }

        if (owner == me)
                return "�Ǳ��ؼ��������������ڿ���";

        if (objectp(owner) && owner != this_object())
        {
                if (! owner->is_character())
                        return "�Ǳ�ɨҶ�ȷ��Ϸ��Ѿ����ȥ�ˡ�";

                if (owner->query("family/family_name") == "�һ���")
                        return "ɨҶ�ȷ�������ʱ����ͬ��" + owner->query("name") +
                               "�ڿ�����Ҫ�þ�ȥ�����ɡ�";
                else
                        return "����ɨҶ�ȷ�����������" + owner->query("name") +
                               "���У���ȥ�������ذɡ�";
        }
        ob->move(this_object());
        command("say ���������ȥ���ɣ���ʲô�������Ի������ҡ�");
        command("give xuanfeng paper to " + me->query("id"));
        return 1;
}

mixed ask_book4()
{
        object me = this_player();

        if (me->query("family/family_name") != "�һ���"
           && ! me->query("can_learn/huang/count"))
                return "���ҹ�����";

        if ((int)me->query("combat_exp") < 1000000)
                return "�����ڵľ���̫�ͣ������ȶ�������������";

        if ((int)me->query_skill("count", 1) < 100)
                return "�������Ҳ����������������ʲô��";

        me->set_temp("taohua/countbook", 1);
        command("nod");
        command("say ��ȥ�������ɣ������������ڱ��ܡ�");
        return 1;
}

mixed ask_yuxiao()
{
        object me;
        object ob;
        object owner;

        me = this_player();

        if (me->query("family/family_name") != "�һ���")
                return "���ҹ�����";

        if (me->query("family/master_id") != query("id"))
                return "��������Ϸ�ĵ�����˵��";

        if (me->query_skill("yuxiao-jian", 1) < 150)
                return "�㻹���Ƚ��������������������˵��";

        if (me->query_skill("chuixiao-jifa", 1) < 150)
                return "�ߣ������ﶼ�����ã����������к��ã�";

        ob = find_object(YUXIAO);
        if (! ob) ob = load_object(YUXIAO);
        owner = environment(ob);
        while (owner)
        {
                if (owner->is_character() || ! environment(owner))
                        break;
                owner = environment(owner);
        }

        if (owner == me)
                return "�Ϸ��ǰ��������������𣿻�����ʲô��";

        if (objectp(owner) && owner != this_object())
        {
                if (! owner->is_character())
                        return "�������ڲ����Ϸ����";

                if (owner->query("family/family_name") == "�һ���")
                        return "����������ʱ����ͬ��" + owner->query("name") +
                               "���ã���Ҫ�þ�ȥ�����ɡ�";
                else
                        return "�Ϸ����������������" + owner->query("name") +
                               "���У���ȥ�������ذɡ�";
        }
        ob->move(this_object());
        set_temp("handing", carry_object("/d/taohua/obj/huaban"));
        command("say ����̿��ù��������Ϸ�ͽ��������㡣");
        command("say ���߽������¶��С�ģ��ɲ�Ҫ�����Ϸ������");
        command("give yu xiao to " + me->query("id"));
        return 1;
}

mixed ask_zhi()
{
        object me = this_player();

        if (me->query("can_perform/jiuyin-shengong/zhi"))
                return "�㲻���Ѿ�������";

        if (! me->query("can_learn/jiuyin-shengong/zhi"))
        {
               tell_object(me, HIG "������º��޹ϸ�Ϊ���д�һ�ʣ�\n" NOR);
               command("tan");
               return 1;
        }

        if (me->query_skill("jiuyin-shengong", 1) < 250)
        {
               command("shake");
               return "������񹦻�򲻹����һ����ܴ������У�";
        }

        if (me->query_skill("finger", 1) < 200)
               return "�����ָ��������죬�Ҳ��ܴ������У�";        
 
        if (me->query_skill("force", 1) < 240)
               return "���ڹ���Ϊ�������Ҳ��ܴ������У�";

        if (me->query_skill("martial-cognize", 1) < 240)
               return "����ѧ�����������Ҳ��ܴ�����У�";

        if (me->query("max_neili") < 5000)
               return "��������Ϊ���㣬�һ����ܴ�����У�";

        command("haha");
        command("say ��Ȼ�������Ҿʹ�����У���ɿ����ˣ�");      
        message_sort(HIM "��ҩʦ���ֳ�ָ����������$N" HIM "ֻ��ָ��������ף���"
                     "��δ��������δ�ţ����Ǽ�$N" HIM "���ۻ����� ����\n" NOR, me);
        
        command("haha");

        command("say ��������");
        if (me->can_improve_skill("finger"))
                me->improve_skill("finger", 1500000);
        if (me->can_improve_skill("jiuyin-shengong"))
                me->improve_skill("jiuyin-shengong", 1500000);
        if (me->can_improve_skill("martial-cognize"))
                me->improve_skill("martial-cognize", 1500000);

        me->set("can_perform/jiuyin-shengong/zhi", 1);
        tell_object(me, HIG "��ѧ���ˡ�������ָ����\n" NOR);
       
        return 1;
}

mixed ask_shou()
{
        object me = this_player();

        if (me->query("can_perform/jiuyin-shengong/shou"))
                return "�㲻���Ѿ�������";

        if (! me->query("can_learn/jiuyin-shengong/shou"))
        {
               tell_object(me, HIG "������º��޹ϸ�Ϊ���д�һ�ʣ�\n" NOR);
               command("tan");
               return 1;
        }

        if (me->query_skill("jiuyin-shengong", 1) < 260)
        {
               command("shake");
               return "������񹦻�򲻹����һ����ܴ������У�";
        }

        if (me->query_skill("hand", 1) < 200)
               return "������ַ�������죬�Ҳ��ܴ������У�";        
 
        if (me->query_skill("force", 1) < 240)
               return "���ڹ���Ϊ�������Ҳ��ܴ������У�";

        if (me->query_skill("martial-cognize", 1) < 240)
               return "����ѧ�����������Ҳ��ܴ�����У�";

        if (me->query("max_neili") < 5000)
               return "��������Ϊ���㣬�һ����ܴ�����У�";

        command("haha");
        command("say ��Ȼ�������Ҿʹ�����У���ɿ����ˣ�");      
        message_sort(HIM "��ҩʦ��������һ���³���һ��������ʽ���أ�������ı���$N"
                     HIM "��ҪѨ���ۼ�$N" HIM "���޴Ӷ�������ҩʦȴͻȻ���У�$N" HIM
                     "����δ����������һ������\n" NOR, me);
        
        command("haha");

        command("say ��������");
        if (me->can_improve_skill("hand"))
                me->improve_skill("hand", 1500000);
        if (me->can_improve_skill("jiuyin-shengong"))
                me->improve_skill("jiuyin-shengong", 1500000);
        if (me->can_improve_skill("martial-cognize"))
                me->improve_skill("martial-cognize", 1500000);

        me->set("can_perform/jiuyin-shengong/shou", 1);
        tell_object(me, HIG "��ѧ���ˡ��������֡���\n" NOR);
       
        return 1;
}

mixed ask_zhang()
{
        object me = this_player();

        if (me->query("can_perform/jiuyin-shengong/zhang"))
                return "�㲻���Ѿ�������";

        if (! me->query("can_learn/jiuyin-shengong/zhang"))
        {
               tell_object(me, HIG "������º��޹ϸ�Ϊ���д�һ�ʣ�\n" NOR);
               command("tan");
               return 1;
        }

        if (me->query_skill("jiuyin-shengong", 1) < 260)
        {
               command("shake");
               return "������񹦻�򲻹����һ����ܴ������У�";
        }

        if (me->query_skill("strike", 1) < 220)
               return "������Ʒ�������죬�Ҳ��ܴ������У�";        
 
        if (me->query_skill("force", 1) < 240)
               return "���ڹ���Ϊ�������Ҳ��ܴ������У�";

        if (me->query_skill("martial-cognize", 1) < 240)
               return "����ѧ�����������Ҳ��ܴ�����У�";

        if (me->query("max_neili") < 5000)
               return "��������Ϊ���㣬�һ����ܴ�����У�";

        command("haha");
        command("say ��Ȼ�������Ҿʹ�����У���ɿ����ˣ�");      
        message_sort(HIM "˫��һ���û���������Ӱ��������������գ��Ʒ�������ƻֺ룬$N"
                     HIM "�ѿ���Ŀ�ɿڴ���\n" NOR, me);

        
        command("haha");

        command("say ��������");
        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("jiuyin-shengong"))
                me->improve_skill("jiuyin-shengong", 1500000);
        if (me->can_improve_skill("martial-cognize"))
                me->improve_skill("martial-cognize", 1500000);

        me->set("can_perform/jiuyin-shengong/zhang", 1);
        tell_object(me, HIG "��ѧ���ˡ��������ơ���\n" NOR);
       
        return 1;
}

int accept_object(object me, object ob) 
{
            int r; 
            if (r = ::accept_object(me, ob)) 
                     return r; 

          if (base_name(ob) != "/clone/lonely/book/zhenjing1")
          
        {
               command("say ��������ֶ�����ʲô��");               
               return 0;
        } 

        command("heihei");        
        command("say �ðɣ���Ȼ�������Ҿʹ�������񹦾��У��������ʱ�����ң�"); 
        destruct(ob);
        me->set("can_learn/jiuyin-shengong/zhi", 1);
        me->set("can_learn/jiuyin-shengong/zhang", 1);
        me->set("can_learn/jiuyin-shengong/shou", 1);
 
        return 1;        
}

void unconcious()
{
        die();
}
