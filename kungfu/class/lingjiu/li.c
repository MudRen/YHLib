#include <ansi.h>;
#include "etc.h"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;

mixed ask_skill();

void create()
{
        set_name("�����", ({ "li furen", "li", "furen"}));
        set("gender", "Ů��");
        set("title", "�Ϻ�Ҭ��������");
        set("age", 37);
        set("long", @LONG
������Ϻ�Ҭ������������ˣ�ֻ����������
�꣬��ͷ�����ǰ�ף��ֳ�һ����״��Ϊ����
�ĵ��ͣ���֪��Ϊ���
LONG );
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
    
        set("qi", 3600);
        set("max_qi", 3600);
        set("jing", 2000);
        set("max_jing", 2000);
        set("neili", 3200);
        set("max_neili", 3200);
        set("jiali", 100);
        set("combat_exp", 1400000);

        set_skill("force", 180);
        set_skill("linji-zhuang", 180);
        set_skill("dodge", 180);
        set_skill("caiyan-gong", 180);
        set_skill("hand", 180);
        set_skill("jieshou-jiushi", 180);
        set_skill("parry", 180);
        set_skill("club", 180);
        set_skill("literate", 140);
        set_skill("martial-cognize", 160);

        map_skill("force", "linji-zhuang");
        map_skill("dodge", "caiyan-gong");
        map_skill("club", "caiyan-gong");
        map_skill("parry", "caiyan-gong");
        map_skill("hand", "jieshou-jiushi");

        prepare_skill("hand", "jieshou-jiushi");

        set("inquiry", ([
                "��ϼ����"   : (: ask_skill :),
                "����"       : "�����������չ��µ�����������ȫ���������",
                "������"     : "�����������չ��µ�����������ȫ���������",
        ]));

        create_family("Ҭ����", 11, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "club.huan" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );

        setup();
        carry_object("/d/lingjiu/npc/obj/diaogan")->wield();
        carry_object("/d/city/npc/cloth/color-dress")->wear();
}

int recognize_apprentice(object ob, string skill)
{
        if (ob->query("family/family_name") != "���չ�")
        {
                command("hmm");
                command("say �����������");
                return -1;
        }

        if (ob->query("family/master_id") != "xuzhu zi")
        {
                command("heng");
                command("say ����ʦ��ȥ��û��ûС��ȱ���̡ܽ�");
                return -1; 

        }

        if (skill != "caiyan-gong" && skill != "club")
        {
                command("say ��ֻ�ܽ���һЩ�������򣬲�ѧ�����ˡ�");
                return -1;
        }

        if (! ob->query_temp("can_learn/lifuren"))
        {
                command("nod2");
                command("say ��Ȼ���������ĵ��ӣ��Ҿͽ�����ˡ�");
                ob->set_temp("can_learn/lifuren", 1);
        }
        return 1;
}

mixed ask_skill()
{
        object me;

        me = this_player();
        if (me->query("can_perform/caiyan-gong/huan"))
                return "�㲻���Ѿ�ѧ�����𣿺ι�����ǲ���";

        if (me->query("family/family_name") != "���չ�" &&
           me->query("family/family_name") != "Ҭ����")
                return "���������������";

        if (me->query_skill("caiyan-gong", 1) < 1)
                return "����๦��δ����������̸ʲô���С�";

        if (me->query("family/family_name") == "���չ�" &&
           me->query("gongxian") < 500)
                return "����������ô������޹��͵ĵ��ӡ�";

        if (me->query_skill("dodge") < 180)
                return "����Ṧ���δ����ѧ�������С�";

        if (me->query_skill("caiyan-gong", 1) < 120)
                return "��Ĳ��๦��򻹲��Զ���ٻ�ȥ������";

        message_vision(HIY "$n" HIY "���˵�ͷ���ȵ����������ˣ���˵��"
                       "����һ�����ѳ�\n�������ڱ��ϵĵ��ͣ��漴������"
                       "������ʱֻ��������һ��\n�����ɶ����ģ����ı��"
                       "���ɰ˱�ʮ�������ó�������Ӱ��\n���̳���ȫȫ��"
                       "��$N" HIY "���ܸ�����λ��\n" NOR, me,
                       this_object());
        command("sweat");
        command("say ���п��������ӣ���ʵȴ��������ϰ��");
        tell_object(me, HIC "��ѧ���ˡ���ϼ��������\n" NOR);
        if (me->can_improve_skill("dodge"))
                me->improve_skill("dodge", 1500000);
        if (me->can_improve_skill("club"))
                me->improve_skill("club", 1500000);
        if (me->can_improve_skill("caiyan-gong"))
                me->improve_skill("caiyan-gong", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/caiyan-gong/huan", 1);
        if (me->query("family/family_name") == "���չ�")
                me->add("gongxian", -500);
        return 1;
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        command("en");
        command("say �ðɣ���Ȼ���������棬�������������ˣ�");
        command("recruit " + ob->query("id"));
}

void unconcious()
{
        die();
}
