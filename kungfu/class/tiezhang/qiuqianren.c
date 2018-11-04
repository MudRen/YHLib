#include <ansi.h>
#include "tiezhang.h"

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;
inherit F_QUESTER;

void create()
{
        set_name("��ǧ��", ({ "qiu qianren", "qiu", "qianren", "ren"}));
        set("nickname", WHT "����ˮ��Ư" NOR);
        set("long", "����������������ư�İ�������ˮ��Ư��ǧ��\n"
                    "��ͷ��԰ף����Ƹ���������ֻ���һ�Ѵ����ȡ�\n" );

        set("gender", "����");
        set("age", 60);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
       
        set("qi", 6000);
        set("max_qi", 6000);
        set("jing", 3000);
        set("max_jing", 3000);
        set("neili", 8000);
        set("max_neili", 8000);
        set("jiali", 200);
        set("combat_exp", 4000000);
        set("score", 40000);

        set_skill("force", 280);
        set_skill("tiezhang-xinfa", 280);
        set_skill("tianlei-shengong", 280);
        set_skill("dodge", 320);
        set_skill("dengping-dushui", 320);
        set_skill("strike", 320);
        set_skill("parry", 280);
        set_skill("tie-zhang", 320);
        set_skill("chuanxin-zhang", 280);
        set_skill("cuff", 280);
        set_skill("tiexian-quan", 280);
        set_skill("unarmed", 280);
        set_skill("feilong-zhang", 260);
        set_skill("staff", 260);
        set_skill("tianlei-dao", 260);
        set_skill("literate", 200);
        set_skill("martial-cognize", 200);

        map_skill("force", "tianlei-shengong");
        map_skill("unarmed", "chuanxin-zhang");
        map_skill("strike", "tie-zhang");
        map_skill("cuff", "tiexian-quan");
        map_skill("parry", "tie-zhang");
        map_skill("dodge", "dengping-dushui");
        map_skill("staff", "feilong-zhang");

        prepare_skill("strike", "tie-zhang");

        create_family("���ư�", 14, "����");

        set("inquiry", ([
                "����"    : "��Ҫ��ʲô���У�",
                "����"    : "��Ҫ��ʲô������",
                "��������": "�Ȿ�ؼ��������������Ѿ�ʧ��ܾ��ˡ�",
                "�Ϲٽ���": "�����ҵ���ҵ��ʦ������������",
                "��ǧ��"  : "�ߣ�������Ǵ����ҵ����ŵ�����ҡײƭ������һ����Ҫ����",
                "��ǧ��"  : "�����¼޵������ȥ�ˣ����������ʲô����",
                "�����"  : "����ȹ���ֹ�Ǽһﲻ�Ǹ�����������������",
                "��ɽ�۽�": "�ߣ�ȥ��Ļ�ɽ�۽�Ҫ������Ϊ���ڱչۣ������ֵ�����������ţ���ӡ�",
        ]));

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "strike.juesha" :),
                (: perform_action, "strike.lei" :),
                (: perform_action, "strike.yin" :),
                (: perform_action, "cuff.kai" :),
                (: perform_action, "unarmed.zhui" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }) );

        setup();

        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 50);
}

void attempt_apprentice(object me)
{
        string purename, name, new_name;

        if (! permit_recruit(me))
                return;

        if ( me->query("family/family_name") &&
             me->query("family/family_name") == "�����" &&
             me->query("family/master_name") == "��ǧ��" )
        {
                command("nod");
                command("say ԭ�������õĺ��ᣬ����Ҳ�ã����Ǳ�������һ���ˡ�����"
                "���ȿ������������\n");
                me->set("move_party/����ȡ����ư�", 1);
        }

        if ((int)me->query("shen") > -60000)
        {
                command("heng");
                command("say ����ǧ��ɲ����Ĵ����������ͽ�ܡ�");
                return;
        }

        if ((int)me->query("combat_exp") < 800000)
        {
                command("heng");
                command("say ������������ܼ̳��ҵ��²���");
                return;
        }

        if ((int)me->query_skill("force") < 260)
        {
                command("say Ҫѧ�ҵ����ƾ������ڹ��Ǿ������ɣ��㻹���ȶ������ɡ�");
                return;
        }

        if ((int)me->query_skill("strike", 1) < 180)
        {
                command("say Ҫѧ�ҵ����ƾ�������Ҫ��տ���Ʒ����������ҿ���������"
                        "���µĹ��򻹲�������");
                return;
        }

        command("say ��������");
        command("say �Ҿ��������ˣ�ϣ������������񹦣���֮������");
        command("recruit " + me->query("id"));

        if ( me->query("move_party/����ȡ����ư�") &&
             me->query("surname") == "����" )
        {
                name = me->query("name");
                purename = me->query("purename");

                new_name = "��" + purename;

                me->set("surname", "��");
                me->set("name", new_name);
                me->delete("move_party/����ȡ����ư�", 1);

                command("say ����ֹ���ϼһﲻ�Ǹ����������Ժ��Ǹ���������Ϊ�á�");
                command("say �ӽ��Ժ���ͽ���" + new_name + "�ɡ�");
        }
}

mixed ask_skill3()
{
        object me;

        me = this_player();
        if (me->query("can_perform/tie-zhang/juesha"))
                return "�������Ѿ��̹����ˣ������Լ���ȥ�����ϰ�ɣ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ������޹ϸ𣬺γ����ԣ�";

        if (me->query_skill("tie-zhang", 1) < 1)
                return "���������Ʒ���ûѧ����̸���ԣ�";

        if (me->query("shen") > -100000)
                return "�Ĵ����������Զ�ɲ��˴��£������㲻ѧҲ�գ�";

        if (me->query_skill("tie-zhang", 1) < 200)
                return "��������Ʒ������ò����ң��Լ���ȥ���������ɣ�";

        if (me->query_skill("tianlei-shengong", 1) < 180)
                return "��һ������ǿ����������������������������µĹ��򻹲�������";

        if (me->query("gongxian") < 660)
                return "������ɹ��ײ����������Ҳ��ܴ��㣡";

        message_vision(HIY "$n" HIY "ĬĬע����$N" HIY "��"
                       "�ã�˵��������Ȼ��ˣ������ұ㴫��"
                       "���У���ֻ��ʾһ�飬���Ҫ����ϸ��"
                       "����\n\n" NOR + HIR "$n" HIR "˵��"
                       "һ��ŭ�ȣ�������������ʮ�ص�������"
                       "�����ȶ����������Ķ���˫�۶�Ȼ��\n"
                       "�����ߡ�ֻ�������ƿ�֮����Ȼ��֮��"
                       "$n" HIR "˫�ƻó�������Ӱ�������"
                       "��������˷�\n��ӿ�������������ư�"
                       "�磬�����ױȣ�\n" NOR,
                       me, this_object());
        command("nod");
        command("say ���С�����ɲ�ơ��������ư���Ϊ�������ʽ���������˶��٣�");
        command("say �����еİ����Ҫ���Լ������ڼ���ϰ�������գ��Լ���ȥ�����ϰ�ɡ�");
        tell_object(me, HIC "��ѧ���ˡ�����ɲ�ơ���һ�С�\n" NOR);
        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 960000);
        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", 960000);
        if (me->can_improve_skill("tie-zhang"))
                me->improve_skill("tie-zhang", 960000);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 960000);
        if (me->can_improve_skill("tianlei-shengong"))
                me->improve_skill("tianlei-shengong", 960000);
        me->set("can_perform/tie-zhang/juesha", 1);
        return 1;
}

mixed ask_skill4()
{
        object me;

        me = this_player();
        if (me->query("can_perform/feilong-zhangfa/fei"))
                return "�������Ѿ��̹����ˣ������Լ���ȥ�����ϰ�ɣ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ������޹ϸ𣬺γ����ԣ�";

        if (me->query_skill("feilong-zhangfa", 1) < 1)
                return "���������ȷ���ûѧ����̸���ԣ�";

        if (me->query("shen") > -10000)
                return "�ٺٺ٣��������Ĵ������ܸɳ�ʲô�£������㲻ѧҲ�գ�";

        if (me->query_skill("feilong-zhangfa", 1) < 150)
                return "��ķ����ȷ������ò����ң��Լ���ȥ���������ɣ�";

        if (me->query("gongxian") < 160)
                return "������ɹ��ײ����������Ҳ��ܴ��㣡";

        message_vision(HIY "$n" HIY "΢΢���˵�ͷ����$N" HIY
                       "˵�����������ˣ����漴˳�ֳ���һ����"
                       "�ȣ�ע�����󣬡�쬡���\nһ��������ɲ"
                       "��ֻ��һ��������Ŷ�����ͬʱֻ������"
                       "�꡹һ�����죬������û��$N" HIY "��"
                       "�����\n������֮�\n" NOR, me, this_object());
        command("nod");
        command("say ���С������ơ��������ӣ��������Լ������ϰ�����ˣ�");
        tell_object(me, HIC "��ѧ���ˡ������ơ���һ�С�\n" NOR);
        if (me->can_improve_skill("staff"))
                me->improve_skill("staff", 960000);
        if (me->can_improve_skill("feilong-zhangfa"))
                me->improve_skill("feilong-zhangfa", 960000);
        me->set("can_perform/feilong-zhangfa/fei", 1);
        return 1;
}

int accept_ask(object me, string topic)
{
        switch (topic)
        {
        case "����" :
        case "����" :
        case "����" :
                return QUEST_D->accept_ask(this_object(), me, topic);
                break;

        case "������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/tie-zhang/lei",
                           "name"    : "������",
                           "msg1"    : HIY "$N" HIY "Ͷ�������"
                                       "һЦ��˵�����������ˣ���" 
                                       "�漴ֻ��$N" HIY "�ʹ���"
                                       "����˫�Ƶ�ʱ��û�죬��"
                                       "������֮��$N" HIY "˫�ƻ�"
                                       "Ϊһ���Ƶ������\nն����"
                                       "��ֻ�������꡹һ��������"
                                       "��һ����ʯ��Ӧ�����飡",
                           "sk1"     : "tie-zhang",
                           "lv1"     : 160,
                           "force"   : 240,
                           "neili"   : 2200,
                           "gongxian": 600,
                           "shen"    : -65000, ]));
                break;

        case "����ɲ��" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/tie-zhang/juesha",
                           "name"    : "����ɲ��",
                           "msg1"    : HIY "$N" HIY "ĬĬע������"
                                       "���ã�˵��������Ȼ��ˣ���"
                                       "���ұ㴫�����У���ֻ��ʾһ"
                                       "�飬���Ҫ����ϸ�ˣ���˵��"
                                       "һ��ŭ�ȣ�������������ʮ��"
                                       "�������������ȶ�����������"
                                       "����˫�۶�Ȼ�������ߡ�ֻ��"
                                       "�����ƿ�֮����Ȼ��֮��$N" HIY 
                                       "˫�ƻó�������Ӱ������ǵ���"
                                       "����˷���ӿ�������������ư�"
                                       "�磬�����ױȣ�", 
                           "sk1"     : "tie-zhang",
                           "lv1"     : 200,
                           "force"   : 300,
                           "neili"   : 2200,
                           "gongxian": 800,
                           "shen"    : -85000, ]));
                break;

        case "��Ӱ��" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/tie-zhang/long",
                           "name"    : "��Ӱ��",
                           "sk1"     : "tie-zhang",
                           "lv1"     : 100,
                           "force"   : 80,
                           "neili"   : 1300,
                           "gongxian": 300,
                           "shen"    : -60000, ]));
                break;

        case "��ָ��" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/tie-zhang/dao",
                           "name"    : "��ָ��",
                           "sk1"     : "tie-zhang",
                           "lv1"     : 180,
                           "force"   : 280,
                           "neili"   : 2500,
                           "gongxian": 700,
                           "shen"    : -90000, ]));
                break;

        case "����ĥ" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/tie-zhang/yin",
                           "name"    : "����ĥ",
                           "sk1"     : "tie-zhang",
                           "lv1"     : 220,
                           "force"   : 300,
                           "neili"   : 3500,
                           "gongxian": 900,
                           "shen"    : -95000, ]));
                break;

        case "����ը��" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/tianlei-dao/zha",
                           "name"    : "����ը��",
                           "sk1"     : "tianlei-dao",
                           "lv1"     : 150,
                           "force"   : 140,
                           "neili"   : 1500,
                           "gongxian": 600,
                           "shen"    : -75000, ]));
                break;

        case "��������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/tianlei-dao/shan",
                           "name"    : "��������",
                           "sk1"     : "tianlei-dao",
                           "lv1"     : 150,
                           "force"   : 150,
                           "neili"   : 1500,
                           "gongxian": 600,
                           "shen"    : -75000, ]));
                break;
/*
        case "�����з�" :
                return MASTER_D->give_item(me, this_object(),
                        ([ "item"    : ZHENYUE,
                           "master"  : 1,
                           "sk1"     : "henshan-jian",
                           "lv1"     : 120,
                           "shen"    : 50000, ]));
                break;
*/
        default:
                return 0;
        }
}

void unconcious()
{
        die();
}

