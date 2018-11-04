#include <ansi.h>
#include "meizhuang.h"

inherit NPC;
inherit F_MASTER;

mixed ask_skill1();
mixed ask_skill2();

void create()
{
        set_name("ͺ����", ({ "tubi weng", "tubi", "tu", "bi", "weng" }));
        set("long", @LONG
������÷ׯ��λׯ�����е�����ͺ���̡�ֻ��
����һ���ɸɾ����İ�ɫ���ۡ�����������
Ѯ����İ�С�����Ϲ�⣬һ����֪���Ǹ���
�׶�ŭ���ˡ�
LONG);
        set("title", "÷ׯ��ׯ��");
        set("nickname", HIR "÷ׯ����" NOR);
        set("gender", "����");
        set("attitude", "friendly");
        set("age", 52);
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
        set("max_qi", 4500);
        set("max_jing", 4000);
        set("neili", 5000);
        set("max_neili", 5000);
        set("jiali", 150);
        set("combat_exp", 2000000);

        set_skill("force", 220);
        set_skill("wuzheng-xinfa", 200);
        set_skill("xuantian-wujigong", 220);
        set_skill("dodge", 200);
        set_skill("meihua-zhuang", 200);
        set_skill("dagger", 220);
        set_skill("shigu-bifa", 220);
        set_skill("parry", 200);
        set_skill("strike", 200);
        set_skill("qingmang-zhang", 200);
        set_skill("calligraphy", 300);
        set_skill("literate", 300);
        set_skill("martial-cognize", 200);

        map_skill("force", "xuantian-wujigong");
        map_skill("dodge", "meihua-zhuang");
        map_skill("parry", "shigu-bifa");
        map_skill("dagger", "shigu-bifa");
        map_skill("strike", "qingmang-zhang");

        prepare_skill("strike", "qingmang-zhang");

        create_family("÷ׯ", 1, "ׯ��");

        set("inquiry", ([
                "����"        : "��Ҫ��ʲô���У�",
                "����"        : "��Ҫ��ʲô������",
                "������"      : "����������������ϴ������������Ѿ�ʧ�ٺܾ��ˡ�",
                "��������"    : "���������书��ɲ⣬�����޵С�",
                "�������"    : "����÷ׯ���Ѻ�����������޹ϸ�������������",
                "������"      : "�Ƴ�����ġ���������������һ����������ȴ��Եһ����",
                "��ʷ�Ѩ"    : (: ask_skill1 :),
                "ʫ���ݺ�"    : (: ask_skill2 :),
        ]));

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "dagger.feng" :),
                (: perform_action, "dagger.shiyi" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }) );

        setup();
        carry_object("/d/city/npc/obj/cloth")->wear();
        carry_object("/d/meizhuang/obj/panguanbi")->wield();
}

void attempt_apprentice(object me)
{
        if (! permit_recruit(me))
                return;

        if ( me->query("family/family_name") &&
             me->query("family/family_name") == "�������" &&
             me->query("family/master_name") == "��������" )
        {
                command("yi");
                command("say �ҵ���˭��ԭ���Ƕ��������ĵ��ӡ�");
                command("say ������Ҳ�����֣���ȥ���Ҵ�硢������ˡ�");
                me->set("move_party/������̡�÷ׯ", 1);
                return;
        }

        if ((int)me->query("combat_exp") < 50000)
        {
                command("sigh");
                command("say ��Ľ�������̫ǳ�������ȶ����������˵�ɡ�");
                return;
        }

        if ((int)me->query_skill("wuzheng-xinfa", 1) < 80
           && (int)me->query_skill("xuantian-wujigong", 1) < 80)
        {
                command("say �������ŵ��ڹ���ûѧ�ã�������������");
                return;
        }

        command("say �ðɣ���Ȼ���������䣬�Ҿ������㡣");
        command("recruit " + me->query("id"));
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/shigu-bifa/feng"))
                return "���Ѿ��̹����ˣ��Լ���ȥ���������Ǹ��Ҿ������ݡ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ������޹ϸ𣬺γ����ԣ�";

        if (me->query_skill("shigu-bifa", 1) < 1)
                return "����ʯ�Ĵ�Ѩ�ʷ���ûѧ����̸���ԣ�";

        if (me->query("gongxian") < 300)
                return "��Ա�ׯ�������Ĺ��ײ�������һ������ʱ�����ܴ��㡣";

        if (me->query_skill("calligraphy", 1) < 100)
                return "�٣������ֶ�д���ã���̸ʲô�ʷ���";

        if (me->query_skill("shigu-bifa", 1) < 100)
                return "���ʯ�Ĵ�Ѩ�ʷ������ò����ң��Լ���ȥ���������ɣ�";

        if (me->query_skill("force") < 150)
                return "����ڹ�����в�������ѧ���ˣ�ѧ���ˡ�";

        message_vision(HIY "$n" HIY "����һЦ��˵���������������ӿ�"
                       "��Ҳ�������Ҿʹ������С�\n$n" HIY "˵��㽫$N"
                       HIY "������ǰ�����ֹ���˵�˰��졣\n" NOR, me,
                       this_object());
        command("nod");
        command("say �ղ�����˵�ı�������ʷ�Ѩ�ľ�Ҫ�����˾���ȥ���ɡ�");
        tell_object(me, HIC "��ѧ���ˡ���ʷ�Ѩ����\n" NOR);

        if (me->can_improve_skill("dagger"))
                me->improve_skill("dagger", 1500000);
        if (me->can_improve_skill("shigu-bifa"))
                me->improve_skill("shigu-bifa", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/shigu-bifa/feng", 1);
        me->add("gongxian", -300);

        return 1;
}

mixed ask_skill2()
{
        object me;

        me = this_player();

        if (me->query("can_perform/shigu-bifa/shiyi"))
                return "���Ѿ��̹����ˣ��Լ���ȥ���������Ǹ��Ҿ������ݡ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ������޹ϸ𣬺γ����ԣ�";

        if (me->query_skill("shigu-bifa", 1) < 1)
                return "����ʯ�Ĵ�Ѩ�ʷ���ûѧ����̸���ԣ�";

        if (me->query("gongxian") < 300)
                return "��Ա�ׯ�������Ĺ��ײ�������һ������ʱ�����ܴ��㡣";

        if (me->query_skill("calligraphy", 1) < 100)
                return "�٣������ֶ�д���ã���̸ʲô�ʷ���";

        if (me->query_skill("shigu-bifa", 1) < 100)
                return "���ʯ�Ĵ�Ѩ�ʷ������ò����ң��Լ���ȥ���������ɣ�";

        if (me->query_skill("force") < 150)
                return "����ڹ�����в�������ѧ���ˣ�ѧ���ˡ�";

        message_vision(HIY "$n" HIY "���˵�ͷ��˵������һ�ױʷ����Ǵ�����"
                       "������ʫ���б仯����\n�ģ�һ����ʮ���֣�ÿ��������"
                       "ʮ���в��ȣ���������ˡ�ֻ��$n" HIY "\nҡͷ���Ե�"
                       "������Ὣ������������ϣ��ͽ������ս����������"
                       "��\n���׳�ա���\n" NOR, me, this_object());
        command("nod " + me->query("id"));
        command("say �ղ���˵�Ķ���ס�����Լ���ȥ���ɡ�");
        tell_object(me, HIC "��ѧ���ˡ�ʫ���ݺ᡹��\n" NOR);

        if (me->can_improve_skill("dagger"))
                me->improve_skill("dagger", 1500000);
        if (me->can_improve_skill("shigu-bifa"))
                me->improve_skill("shigu-bifa", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/shigu-bifa/shiyi", 1);
        me->add("gongxian", -300);

        return 1;
}