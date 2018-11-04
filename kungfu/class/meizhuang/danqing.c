#include <ansi.h>
#include "meizhuang.h"

inherit NPC;
inherit F_MASTER;

mixed ask_skill1();

void create()
{
        set_name("������", ({ "danqing sheng", "danqing", "dan", "qing", "sheng" }));
        set("long", @LONG
ֻ�������׳���������������һֻ�Ʊ�������
����Ȼ�������⣬�����÷ׯ��λׯ�����е�
�ĵĵ����������þơ��û����ý����˳�������
����֮�У��Ծ�Ϊ�ף������֮��������ĩ��
LONG);
        set("title", "÷ׯ��ׯ��");
        set("nickname", HIR "÷ׯ����" NOR);
        set("gender", "����");
        set("age", 54);
        set("attitude", "peaceful");
        set("str", 35);
        set("int", 35);
        set("con", 35);
        set("dex", 35);

        set("max_qi", 3500);
        set("max_jing", 3000);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 140);
        set("combat_exp", 1000000);

        set_skill("force", 180);
        set_skill("wuzheng-xinfa", 180);
        set_skill("xuantian-wujigong", 180);
        set_skill("dodge", 180);
        set_skill("zuixian-bu", 180);
        set_skill("parry", 180);
        set_skill("sword", 200);
        set_skill("unarmed", 180);
        set_skill("zuiquan-sanda", 180);
        set_skill("pomopima-jian", 200);
        set_skill("strike", 180);
        set_skill("qingmang-zhang", 180);
        set_skill("literate", 180);
        set_skill("drawing", 220);
        set_skill("liquor", 240);
        set_skill("martial-cognize", 180);

        map_skill("force", "xuantian-wujigong");
        map_skill("dodge", "zuixian-bu");
        map_skill("parry", "pomopima-jian");
        map_skill("sword", "pomopima-jian");
        map_skill("strike", "qingmang-zhang");
        map_skill("unarmed", "zuiquan-sanda");

        prepare_skill("unarmed", "zuiquan-sanda");

        create_family("÷ׯ", 1, "ׯ��");

        set("inquiry", ([
                "����"        : "��Ҫ��ʲô���У�",
                "����"        : "��Ҫ��ʲô������",
                "������"      : "����������������ϴ������������Ѿ�ʧ�ٺܾ��ˡ�",
                "��������"    : "���������书��ɲ⣬�����޵С�",
                "�������"    : "����÷ׯ���Ѻ�����������޹ϸ�������������",
                "Ϫɽ����ͼ"  : "��һֱ�뿴�����η�������Ϫɽ����ͼ�������������ġ�",
                "����Ǭ��"    : (: ask_skill1 :),
        ]));

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "sword.zui" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),

        }) );

        setup();
                
        carry_object("clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
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

        command("en");
        command("say �����Ժ�͸����Ұɡ�");
        command("recruit " + me->query("id"));
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/pomopima-jian/zui"))
                return "���Ѿ��̹����ˣ��Լ���ȥ���������Ǹ��Ҿ������ݡ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ������޹ϸ𣬺γ����ԣ�";

        if (me->query_skill("pomopima-jian", 1) < 1)
                return "������ī���齣��ûѧ����̸���ԣ�";

        if (me->query("gongxian") < 300)
                return "��Ա�ׯ�������Ĺ��ײ�������һ������ʱ�����ܴ��㡣";

        if (me->query_skill("pomopima-jian", 1) < 120)
                return "�����ī���齣�����ò����ң��Լ���ȥ���������ɣ�";

        if (me->query_skill("force") < 150)
                return "����ڹ�����в�������ѧ������һ�С�";

        message_vision(HIY "$n" HIY "����һЦ���������оƱ�һ����"
                       "�ɣ�˵�����ã������Ϸ�㴫�����У�\n$n" HIY
                       "˵�������������䣬һ���������ڵ��£����"
                       "��һ���죬�������\nԾ����������֮�⡣ֻ"
                       "������δվ��������������ǰ��������ԲȦ����"
                       "��\n������Ȧ��������Ȧ����������֮�����"
                       "����ͣ��Ƭ�̣�������$N" HIY "��ǰ��\nȥ��"
                       "�⼸���������ɵĹ�Ȧ����֮�Ʋ���һ�ֵ罣��"
                       "���������������ң���\n��Ϯ�塣ֱ����$N" HIY
                       "Ŀ�ɿڴ���\n" NOR, me, this_object());
        command("haha");
        command("say ��Ҫ������ˣ��Լ���ȥ���ɡ�");
        tell_object(me, HIC "��ѧ���ˡ�����Ǭ������\n" NOR);

        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("pomopima-jian"))
                me->improve_skill("pomopima-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/pomopima-jian/zui", 1);
        me->add("gongxian", -300);

        return 1;
}
