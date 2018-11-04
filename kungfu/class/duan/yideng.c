#include <ansi.h>
#include "duan.h"

inherit NPC;
inherit F_MASTER;

mixed ask_skill1();

void create()
{
    	set_name("һ�ƴ�ʦ", ({ "yideng dashi", "yideng", "dashi" }));
    	set("long", @LONG
һ�ƴ�ʦ�˽������˳ơ���а�������ϵ۱�ؤ����
���ϵ۶λ�ү������ƾ�Ŷ��ϡ�һ��ָ����������
�֣�������֡���ȴ������ʱ��һ�α��������Ϊ
ɮ��֮��󳹴��򣬳�Ϊһλ�õ���ɮ��
LONG );
    	set("title", "�������λ�ʵ�");
    	set("nickname", HIY "�ϵ�" NOR);
    	set("gender", "����");
    	set("age", 71);
	set("shen_type", 1);
    	set("attitude", "friendly");

    	set("str", 33);
    	set("int", 35);
    	set("con", 38);
    	set("dex", 33);

    	set("qi", 6500);
    	set("max_qi", 6500);
    	set("jing", 5000);
    	set("max_jing", 5000);
    	set("neili", 8000);
    	set("max_neili", 8000);
    	set("jiali", 200);
    	set("combat_exp", 4000000);
    	set("score", 500000);

        set_skill("force", 340);
        set_skill("xiantian-gong", 240);
        set_skill("duanshi-xinfa", 320);
        set_skill("kurong-changong", 320);
        set_skill("dodge", 320);
        set_skill("tiannan-bu", 320);
        set_skill("cuff", 300);
        set_skill("jinyu-quan", 300);
        set_skill("strike", 300);
        set_skill("wuluo-zhang", 300);
        set_skill("sword", 300);
        set_skill("staff", 300);
        set_skill("duanjia-jian", 300);
        set_skill("finger", 340);
        set_skill("qiantian-zhi", 340);
        set_skill("yiyang-zhi", 340);
        set_skill("parry", 300);
        set_skill("jingluo-xue", 300);
        set_skill("buddhism", 340);
        set_skill("literate", 300);
        set_skill("sanscrit", 300);
        set_skill("martial-cognize", 320);

        map_skill("force", "xiantian-gong");
        map_skill("dodge", "tiannan-bu");
        map_skill("finger", "yiyang-zhi");
        map_skill("cuff", "jinyu-quan");
        map_skill("strike", "wuluo-zhang");
        map_skill("parry", "yiyang-zhi");
        map_skill("sword", "duanjia-jian");
        map_skill("staff", "yiyang-zhi");

        prepare_skill("finger", "yiyang-zhi");

        create_family("���ϻ���", 11, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "finger.jian" :),
                (: perform_action, "finger.qian" :),
                (: perform_action, "finger.dian" :),
                (: perform_action, "finger.die" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

    	set("inquiry",([
          	"������"   : "����ͨ�������������������ĺ��������",
          	"����"     : "�������ĳ���ǰ��һ����Ե������Ҳ�ա�",
          	"����ͯ"   : "�Ǻǣ������书��ǿ�������Ļ�ȴ����ͯһ�㡣",
          	"�ܲ�ͨ"   : "�Ǻǣ������书��ǿ�������Ļ�ȴ����ͯһ�㡣",
          	"����"     : "Ŷ���Ǹ���С���ĵ��������Һ���ʵ��û����һ��Ҫ�Կ���",
         	"����"     : "�ǹ����Ǻ�С�ӵİ��°ɣ��˵����ǻ��顣",
          	"֪ʶ"     : "�ҿ��Դ����������ķ������ģ������������ʦ��ѧϰ�ɡ�",
          	"����"     : "�ҿ��Դ����������ķ������ģ������������ʦ��ѧϰ�ɡ�",
          	"��������" : (: ask_skill1 :),
    	]));

        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

    	setup();
    	carry_object("/clone/cloth/seng-cloth")->wear();
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
        if (! ob || environment(ob) != environment()) return;

        if ((int)ob->query("shen") < -50000)
                command("say ��λʩ�������������أ�Ȱʩ������Ϊ֪��");

        else
        if ((int)ob->query("shen") < -5000)
                command("say ��λʩ�����м�ħ������������");

        else
        if ((int)ob->query("shen") < 0)
                command("say ��λʩ�������н��������е����������߽�аħ�����");

        else
        if ((int)ob->query("shen") > 50000)
                command("say ʩ�����¹������䣬�պ��Ϊ�����̳���");

        else
                command("say ��λʩ�����������������ߣ���ʩ����ӱ��ء�");

        return;
}

int recognize_apprentice(object me, string skill)
{
        if (me->query("shen") < 0)
        {
                command("say ʩ�������������أ���������֮�������Իᴫ�ڸ��㡣");
                return -1;
        }

        if (skill != "sanscrit" && skill != "buddhism")
        {
                command("say ��Щ���������ʦ��ѧ�ɣ�����ֻ�ܴ���Щ֪ʶ���㡣");
                return -1;
        }

        if (skill == "buddhism" && me->query_skill("buddhism", 1) > 199)
        {
                command("haha");
                command("say ��ķ������Ѿ���ͬ�����ˣ�ʣ�µ��Լ�ȥ�о��ɡ�");
                return -1;
        }

        if (! me->query_temp("can_learn/yideng"))
        {
                command("say ���ް���٢��");
                command("say ��Ȼʩ��������������Ե��������ڡ�");
                me->set_temp("can_learn/yideng", 1);
        }

        return 1;
}

mixed ask_skill1()
{
        object me;

        me = this_player();
        if (me->query("can_perform/yiyang-zhi/die"))
                return "��һ��ָ�������־��磬������ûʲô�ɽ̵��ˡ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return "ʩ���������ز���ʶ����֪ʩ���˻��Ӻ�˵��";

        if (me->query_skill("yiyang-zhi", 1) < 1)
                return "����һ��ָ����ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 2500)
                return "��Ϊ�����������Ĺ��׻�����������������ʱ�����ܴ��㡣";

        if (me->query("shen") < 50000)
                return "����������»����ò���������������ʱ�����ܴ��㡣";

        if (me->query_skill("force") < 300)
                return "���ڹ�����Ϊ�������������������ɡ�";

        if (me->query("max_neili") < 5000)
                return "���������Ϊ�����������ߵ������ɡ�";

        if (me->query_skill("jingluo-xue", 1) < 200)
                return "��Ծ���ѧ���˽⻹��͸�����о�͸���������Ұɡ�";

        if (me->query_skill("yiyang-zhi", 1) < 200)
                return "���һ��ָ����������������������˵�ɡ�";

        message_sort(HIY "\n$n" HIY "������$N" HIY "��һ������漴���˵�"
                     "ͷ����$N" HIY "������ߣ��ڶ��Ե���ϸ˵���ã�$N" HIY
                     "������ĵ�һЦ��������$n" HIY "�Ľ̵���������\n\n"
                     NOR, me, this_object()); 

        command("buddhi");
        command("say �����ѽ��˾������ڸ��㣬�м�Ī�߽�аħ�����");
        tell_object(me, HIC "��ѧ���ˡ�������������\n" NOR);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("jingluo-xue"))
                me->improve_skill("jingluo-xue", 1500000);
        if (me->can_improve_skill("jingluo-xue"))
                me->improve_skill("jingluo-xue", 1500000);
        if (me->can_improve_skill("jingluo-xue"))
                me->improve_skill("jingluo-xue", 1500000);
        if (me->can_improve_skill("finger"))
                me->improve_skill("finger", 1500000);
        if (me->can_improve_skill("finger"))
                me->improve_skill("finger", 1500000);
        if (me->can_improve_skill("finger"))
                me->improve_skill("finger", 1500000);
        if (me->can_improve_skill("yiyang-zhi"))
                me->improve_skill("yiyang-zhi", 1500000);
        if (me->can_improve_skill("yiyang-zhi"))
                me->improve_skill("yiyang-zhi", 1500000);
        if (me->can_improve_skill("yiyang-zhi"))
                me->improve_skill("yiyang-zhi", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/yiyang-zhi/die", 1);
        me->add("gongxian", -2500);

        return 1;
}
