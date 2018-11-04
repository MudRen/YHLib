#include <ansi.h>
#include "meizhuang.h"

#define YAOQIN    "/clone/lonely/yaoqin"
#define DONGXIAO  "/clone/lonely/dongxiao"

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;

mixed ask_skill1();
mixed ask_skill2();
mixed ask_skill3();
mixed ask_xiao();
mixed ask_qin();

void create()
{
        object ob;
        set_name("���ӹ�", ({ "huangzhong gong", "huang", "zhong", "huangzhong", "gong" }));
        set("long", @LONG
�����÷ׯ��λׯ�����е�һ�Ļ��ӹ���ֻ��
����һ���ɸɾ����Ļ�ɫ���ۡ���Ȼ������
��Ѯ������Ȼ�����ӡ�������еȣ����ݺ�
�����ס�
LONG);
        set("title", "÷ׯ��ׯ��");
        set("nickname", HIR "÷ׯ����" NOR);
        set("gender", "����");
        set("age", 62);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 38);
        set("int", 38);
        set("con", 38);
        set("dex", 38);

        set("max_qi", 6000);
        set("max_jing", 5000);
        set("neili", 6000);
        set("max_neili", 6000);
        set("jiali", 200);
        set("combat_exp", 2500000);

        set_skill("force", 260);
        set_skill("wuzheng-xinfa", 240);
        set_skill("xuantian-wujigong", 260);
        set_skill("dodge", 260);
        set_skill("meihua-zhuang", 260);
        set_skill("parry", 260);
        set_skill("sword", 260);
        set_skill("unarmed", 260);
        set_skill("qixian-wuxingjian", 260);
        set_skill("cuff", 240);
        set_skill("zuiquan-sanda", 240);
        set_skill("claw", 200);
        set_skill("longzhua-gong", 200);
        set_skill("strike", 240);
        set_skill("qingmang-zhang", 240);
        set_skill("literate", 240);
        set_skill("buddhism", 150);
        set_skill("tanqin-jifa", 300);
        set_skill("guangling-san", 300);
        set_skill("qingxin-pushan", 300);
        set_skill("martial-cognize", 240);

        set("no_teach", ([
                "longzhua-gong"  : "��צ�������շ�֤��ʦ���ڵ�����"
                                   "��ѧ���Ϸ���֮һ���������ڽ̡�",
        ]));

        map_skill("force", "xuantian-wujigong");
        map_skill("dodge", "meihua-zhuang");
        map_skill("parry", "qixian-wuxingjian");
        map_skill("sword", "qixian-wuxingjian");
        map_skill("unarmed", "qixian-wuxingjian");
        map_skill("strike", "qingmang-zhang");
        map_skill("cuff", "zuiquan-sanda");
        map_skill("claw", "longzhua-gong");
        map_skill("tanqin-jifa", "guangling-san");

        prepare_skill("unarmed", "qixian-wuxingjian");

        create_family("÷ׯ", 1, "ׯ��");

        set("inquiry", ([
                "����"        : "��Ҫ��ʲô���У�",
                "����"        : "��Ҫ��ʲô������",
                "������"      : "����������������ϴ������������Ѿ�ʧ�ٺܾ��ˡ�",
                "��������"    : "���������书��ɲ⣬�����޵С�",
                "�������"    : "����÷ׯ���Ѻ�����������޹ϸ�������������",
                "����ɢ"      : "������˵���ڡ�����ɢ���ס�������������֪�����Ǽ١�",
                "����������"  : (: ask_skill1 :),
                "���һ�����"  : (: ask_skill2 :),
                "����������"  : (: ask_skill3 :),
                "������"    : (: ask_xiao :),
                "��������"    : (: ask_qin :),
        ]));

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "sword.yin" :),
                (: perform_action, "sword.shan" :),
                (: perform_action, "sword.zhu" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),

        }) );

        setup();

        if (clonep())
        {
                ob = find_object(YAOQIN);
                if (! ob) ob = load_object(YAOQIN);
                if (! environment(ob))
                {
                        ob->move(this_object());
                        ob->wield();
                } else
                {
                        ob = new("/d/meizhuang/obj/qin");
                        ob->move(this_object());
                        ob->wield();
                }
        }
        carry_object("/d/quanzhen/npc/obj/greenrobe")->wear();
}

void attempt_apprentice(object me)
{
        string purename, name, new_name;

        if (! permit_recruit(me))
                return;

        if ( me->query("family/family_name") &&
             me->query("family/family_name") == "�������" &&
             me->query("family/master_name") == "��������" )
        {
                command("hmm");
                command("say ԭ���Ƕ��������ĵ��ӣ����㡭�����ûʲô���⡣");
                command("say ����������֮ǰ���ҵ��ȿ���һ�����������");
                me->set("move_party/������̡�÷ׯ", 1);
        }

        if ((int)me->query("combat_exp") < 400000)
        {
                command("sigh");
                command("say ��Ľ�������̫ǳ�������ȶ����������˵�ɡ�");
                return;
        }

        if ((int)me->query_skill("force") < 180)
        {
                command("say ѧ���������ν����ڹ��Ǿ������ɣ��㻹���ȶ������ɡ�");
                return;
        }

        if ((int)me->query_skill("sword", 1) < 100)
        {
                command("say ��Ҫѧ���������ν����㻹���ڽ����϶��¹���");
                return;
        }

        if ((int)me->query_skill("unarmed", 1) < 100)
        {
                command("say ��Ҫѧ���������ν����㻹����ȭ���϶��¹���");
                return;
        }

        command("say ��������");
        command("say �Ҿ��������ˣ�����ǧ��������Ƿǣ�����÷ׯ���ҡ�");
        command("recruit " + me->query("id"));

        if (me->query("move_party/������̡�÷ׯ"))
        {
                me->delete("move_party/������̡�÷ׯ", 1);
                command("say �������Ϊ��÷ׯ���ˣ�����ר�����䣬����ȥ���ʽ������");
        }
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/qixian-wuxingjian/yin"))
                return "�㲻���Ѿ�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ������޹ϸ𣬺γ����ԣ�";

        if (me->query_skill("qixian-wuxingjian", 1) < 1)
                return "�����������ν���ûѧ����̸���ԣ�";

        if (me->query("gongxian") < 500)
                return "��Ա�ׯ�������Ĺ��ײ�������һ������ʱ�����ܴ��㡣";

        if (me->query_skill("force") < 250)
                return "����ڹ�����㣬ѧ������һ�У�";

        if (me->query_skill("qixian-wuxingjian", 1) < 160)
                return "����������ν������ò����ң��Լ���ȥ���������ɡ�";

        if (me->query_skill("tanqin-jifa", 1) < 120)
                return "����ټ���������죬���ò�����һ�С�";

        message_vision(HIY "$n" HIY "΢΢һЦ��ת��������ȡ��һ��"
                       "���ף�ָ������һ�ζ�$N" HIY "ϸ˵\n���ã�$N"
                       HIY "һ����һ�ߵ�ͷ��\n" NOR, me, this_object());
        command("nod");
        command("say ����������������İ������ڣ���������ˣ�");
        tell_object(me, HIC "��ѧ���ˡ���������������\n" NOR);

        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", 1500000);
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("qixian-wuxingjian"))
                me->improve_skill("qixian-wuxingjian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/qixian-wuxingjian/yin", 1);
        me->add("gongxian", -500);

        return 1;
}

mixed ask_skill2()
{
        object me;

        me = this_player();

        if (me->query("can_perform/qixian-wuxingjian/shan"))
                return "�㲻���Ѿ�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ������޹ϸ𣬺γ����ԣ�";

        if (me->query_skill("qixian-wuxingjian", 1) < 1)
                return "�����������ν���ûѧ����̸���ԣ�";

        if (me->query("gongxian") < 500)
                return "��Ա�ׯ�������Ĺ��ײ�������һ������ʱ�����ܴ��㡣";

        if (me->query_skill("force") < 250)
                return "����ڹ�����㣬ѧ������һ�У�";

        if (me->query_skill("qixian-wuxingjian", 1) < 160)
                return "����������ν������ò����ң��Լ���ȥ���������ɣ�";

        if (me->query_skill("tanqin-jifa", 1) < 120)
                return "����ټ���������죬���ò�����һ�С�";

        message_vision(HIY "$n" HIY "���˵�ͷ����$N" HIY "����"
                       "��ߣ��ڶ��Ե���ϸ˵���ã�$N" HIY "��"
                       "����ĵ�\nһЦ��������������\n" NOR, me,
                       this_object());
        command("nod");
        command("say �ղ�����˵�ı������һ������ľ�Ҫ����ɼ����ˣ�");
        tell_object(me, HIC "��ѧ���ˡ����һ���������\n" NOR);

        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", 1500000);
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("qixian-wuxingjian"))
                me->improve_skill("qixian-wuxingjian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/qixian-wuxingjian/shan", 1);
        me->add("gongxian", -500);

        return 1;
}

mixed ask_skill3()
{
        object me;

        me = this_player();

        if (me->query("can_perform/qixian-wuxingjian/zhu"))
                return "�̵ܽ����Ѿ������ˣ����Լ���ȥ�����ϰ�ɡ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ������޹ϸ𣬺γ����ԣ�";

        if (me->query_skill("qixian-wuxingjian", 1) < 1)
                return "�����������ν���ûѧ����̸���ԣ�";

        if (me->query("gongxian") < 2000)
                return "��Ա�ׯ�������Ĺ��ײ�������һ������ʱ�����ܴ��㡣";

        if (me->query_skill("force") < 300)
                return "����ڹ�����㣬ѧ������һ�У�";

        if (me->query_skill("qixian-wuxingjian", 1) < 180)
                return "����������ν������ò����ң��Լ���ȥ���������ɣ�";

        if (me->query_skill("tanqin-jifa", 1) < 150)
                return "����ټ���������죬���ò�����һ�С�";

        message_vision( HIW "$n" HIW "΢΢һЦ��Ҳ���𻰣�ת��������"
                       "���٣�������ǰ�������Ū����ʱ����\n����ʱ��"
                       "ʱ����������Ȼ�����������Ȼ���죬����һ�ᣬ��"
                       "��Խ��Խ����$N" HIW "ֻ\n�������񲻶�����������"
                       "�����ڴ�ʱ���������죬������һ����$N" HIW
                       "���˳�һ����\n�����������£��㲻��������������"
                       "����$N" HIW "��ɫѩ�ף����˶��񣬲ŵ�����ʦ����"
                       "\n���ν������������������������ݴ��ͻ���������"
                       "����˭�ܵ��ܵ��ˣ���$n" HIW "��\n�����һЦ��\n"
                       NOR, me, this_object());
        command("haha");
        command("say ���б��ǡ�������ɽ���񼼣��ֳ�����������㿴�����˶��٣�");
        tell_object(me, HIC "��ѧ���ˡ������������\n" NOR);

        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", 1500000);
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("qixian-wuxingjian"))
                me->improve_skill("qixian-wuxingjian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/qixian-wuxingjian/zhu", 1);
        me->add("gongxian", -2000);

        return 1;
}

mixed ask_xiao()
{
        object me;
        object ob;
        object owner;

        me = this_player();

        if (me->query("family/family_name") != "÷ׯ")
                return "��ͱ�ׯ����ԨԴ����������ʲô��";

        if (me->query("family/master_id") != query("id"))
                return "ֻ���ҵĵ��Ӳ���ʹ���������";

        ob = find_object(DONGXIAO);
        if (! ob) ob = load_object(DONGXIAO);
        owner = environment(ob);
        while (owner)
        {
                if (owner->is_character() || ! environment(owner))
                        break;
                owner = environment(owner);
        }

        if (owner == me)
                return "�����������ﲻ������������Ϊ���޹�����ǲ�Ϸ�";

        if (objectp(owner) && owner != this_object())
        {
                if (! owner->is_character())
                        return "��������һ�������Ѿ���������������ͬ��ʦ����ȥ�ˡ�";

                if (owner->query("family/family_name") == "÷ׯ")
                        return "������������ʱ����ͬ��" + owner->query("name") +
                               "���ã���Ҫ�þ�ȥ�����ɡ�";
                else
                        return "�ҵ�����������������" + owner->query("name") +
                               "���У���ȥ�����һ����ɣ�";
        }

        ob->move(this_object());
        message_vision(HIC "$N" HIC "΢΢һЦ���������ã�����ͽ�������Ѿõ���������"
                       "�㡣��\n" NOR, this_object(), me);
        command("give lvyu dongxiao to " + me->query("id"));
        return 1;
}

mixed ask_qin()
{
        object me;
        object ob;

        me = this_player();

        if (me->query("family/family_name") != "÷ׯ")
                return "��ͱ�ׯ����ԨԴ����������ʲô��";

        if (me->query("family/master_id") != query("id"))
                return "ֻ���ҵĵ��Ӳ���ʹ����������١�";

        if (me->query_skill("qixian-wuxingjian", 1) < 150)
                return "�㻹����ȥ������������ν����������ɡ�";

        if (me->query_skill("tanqin-jifa", 1) < 150)
                return "�����ٶ������ã����ﻹҪ������������٣�";

        if (present("baiyu yaoqin", me))
                return "���ڰ������ٲ�������������Ϊ���޹�����ǲ�Ϸ�";

        ob = present("baiyu yaoqin", this_object());

        if (! objectp(ob))
                return "���ڰ��������Ѿ������������ˡ�";

        ob->move(this_object());
        command("give baiyu yaoqin to " + me->query("id"));

        ob = new("/d/meizhuang/obj/qin");
        ob->move(this_object());
        ob->wield();

        return "�ܺã���Ȼ����������������������ʱ��ȥ�ðɡ�";
}

int accept_object(object me, object ob)
{
        if (base_name(ob) != DONGXIAO
           && base_name(ob) != YAOQIN)
        {
                command("say ��������ֶ�����ʲô��");
                return 0;
        }

        if (me->query("family/master_id") != query("id"))
                command("say ��л��λ" + RANK_D->query_respect(me) +
                        "���ҵı������ء�");
        else
                command("say �ܺã��ܺã�");
        destruct(ob);
        return 1;
}

