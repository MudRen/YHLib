#include <ansi.h>
#include "honghua.h"

inherit NPC;
inherit F_MASTER;

mixed ask_skill1();

void create()
{
        set_name("���", ({ "luo bing", "luo", "bing"}));
        set("title", "�컨��ʮһ����");
        set("nickname", HIC "ԧ�쵶" NOR);
        set("long", "����һ���������ٸ���һ�̵ֶ���һ������һ\n"
                    "��������\n");
        set("gender", "Ů��");
        set("age", 34);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("per", 21);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("qi", 1800);
        set("max_qi", 1800);
        set("jing", 1200);
        set("max_jing", 1200);
        set("neili", 2500);
        set("max_neili", 2500);
        set("jiali", 80);
        set("combat_exp", 500000);
        set("score", 1000);

        set_skill("force", 120);
        set_skill("honghua-xinfa", 120);
        set_skill("unarmed", 120);
        set_skill("changquan", 120);
        set_skill("dodge", 140);
        set_skill("yanzi-chuanyun", 140);
        set_skill("blade", 140);
        set_skill("hanwang-qingdao", 140);
        set_skill("parry", 120);
        set_skill("martial-cognize", 100);
        set_skill("literate", 140);

        map_skill("force"  , "honghua-xinfa");
        map_skill("blade"  , "hanwang-qingdao");
        map_skill("unarmed" , "changquan");
        map_skill("dodge"  , "yanzi-chuanyun");
        map_skill("parry"  , "hanwang-qingdao");

        prepare_skill("unarmed", "changquan");

        create_family("�컨��", 4, "����");

        set("inquiry", ([
                "��Ӱ����"  : (: ask_skill1 :),
        ]));

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "blade.ying" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );
        setup();

        carry_object("/clone/cloth/jinduan")->wear();
        carry_object("/clone/weapon/gangdao")->wield();    
}

void attempt_apprentice(object me)
{
        if (! permit_recruit(me))
                return;

        if ((int)me->query("shen") < -1000)
        {
                command("say �Һ컨�᲻�ղ���֮�ˣ��㻹���߰ɡ�");
                return;
        }

        command("xixi");
        command("say ��Ȼ�������Ҿ���������ˡ�");
        command("recruit " + me->query("id"));
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/hanwang-qingdao/ying"))
                return "�㲻���Ѿ�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ������޹ϸ𣬺γ����ԣ�";

        if (me->query_skill("hanwang-qingdao", 1) < 1)
                return "���������൶��ûѧ����̸���ԣ�";

        if (me->query("gongxian") < 80)
                return "���ڻ��������Ĺ��׻������������Ҳ�æ���㡣";

        if (me->query("shen") < 5000)
                return "�������������ò����������Ҳ��ܴ��㡣";

        if (me->query_skill("force") < 120)
                return "����ڹ�����㣬ѧ������һ�У�";

        if (me->query_skill("hanwang-qingdao", 1) < 80)
                return "��ĺ����൶�����ò����ң��Լ���ȥ���������ɣ�";

        message_vision(HIY "$n" HIY "���˵�ͷ����$N" HIY "����"
                       "��ߣ��ڶ��Ե���ϸ˵���ã�$N" HIY "��"
                       "�����\n��һЦ��������������\n" NOR,
                       me, this_object());

        command("nod");
        command("say �ղ�����˵�ı��Ǻ����൶�ľ�Ҫ����ɼ����ˣ�");
        tell_object(me, HIC "��ѧ���ˡ���Ӱ���ء���\n" NOR);

        if (me->can_improve_skill("blade"))
                me->improve_skill("blade", 1500000);
        if (me->can_improve_skill("hanwang-qingdao"))
                me->improve_skill("hanwang-qingdao", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/hanwang-qingdao/ying", 1);
        me->add("gongxian", -80);

        return 1;
}
