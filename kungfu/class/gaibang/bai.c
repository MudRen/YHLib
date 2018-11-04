#include <ansi.h>
#include "gaibang.h"

inherit NPC;
inherit F_MASTER;

#include "fight.h"

mixed ask_skill1();

void create()
{
        set_name("������", ({ "bai shijing", "bai", "shijing" }));
        set("long", @LONG
����һλ��ü�԰׵���ؤ��˫Ŀ��͸��һ˿��
����������ؤ��Ĵ������ϰ����������õĲ�
˿�������������������Ѿá�
LONG);
        set("nickname", HIR "���峤��" NOR);
        set("title", "ؤ��Ŵ�����");
        set("gender", "����");
        set("age", 48);
        set("attitude", "peaceful");
        set("class", "beggar");

        set("str", 35);
        set("int", 35);
        set("con", 35);
        set("dex", 35);

        set("max_qi", 4000);
        set("max_jing", 3000);
        set("neili", 4300);
        set("max_neili", 4300);
        set("jiali", 180);
        set("combat_exp", 2200000);
        set("score", 300000);
        set("shen_type", 1);
        
        set_skill("force", 220);
        set_skill("jiaohua-neigong", 180);
        set_skill("huntian-qigong", 220);
        set_skill("dodge", 220);
        set_skill("feiyan-zoubi", 220);
        set_skill("unarmed", 200);
        set_skill("changquan", 200);
        set_skill("jueming-tui", 200);
        set_skill("strike", 200);
        set_skill("tongchui-zhang", 200);
        set_skill("hand", 240);
        set_skill("chansi-shou", 240);
        set_skill("parry", 200);
        set_skill("staff", 220);
        set_skill("jiaohua-bangfa", 220);
        set_skill("begging", 250);
        set_skill("checking", 250);
        set_skill("literate", 180);
        set_skill("martial-cognize", 200);

        map_skill("force", "huntian-qigong");
        map_skill("unarmed", "jueming-tui");
        map_skill("strike", "tongchui-zhang");
        map_skill("staff", "jiaohua-bangfa");
        map_skill("hand", "chansi-shou");
        map_skill("parry", "chansi-shou");
        map_skill("dodge", "feiyan-zoubi");

        prepare_skill("hand", "chansi-shou");

        create_family("ؤ��", 18, "����");

        set("inquiry", ([
                "��˿����" : (: ask_skill1 :),
        ]));

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "hand.qin" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 150);
        set_temp("apply/armor", 200);

        setup();
        carry_object("/d/gaibang/npc/obj/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        string title = ob->query("title");
        int lvl = ob->query("family/beggarlvl");

        if (! permit_recruit(ob))
                return;

        if (ob->query("combat_exp") < 120000)
        {
                command("say ��Ľ������鲻�������������λ����ѧϰ�ɡ�");
                return;
        }

        if (ob->query("shen") < 20000)
        {
                command("say ����Ϊؤ����ӣ���Ȼ�������£�");
                return;
        }

        if (ob->query("family/beggarlvl") < 4)
        {
                command("say ���ڱ���ĵ�λ̫�ͣ�������������ʦ��ѧϰ�ɡ�");
                return;
        }

        if (ob->query_skill("force") < 90)
        {
                command("say ����ڹ���򻹲�����������������ʦ��ѧϰ�ɡ�");
                return;
        }
        command("hmm");
        command("say ����������ǣ��ɱ�������鷳��");
        command("recruit " + ob->query("id"));

        if (ob->query("class") != "beggar")
                ob->set("class", "beggar");

        if (lvl > 0)
        {
                ob->set("family/beggarlvl", lvl);
                ob->set("title", title);
        }
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/chansi-shou/qin"))
                return "�����Ҳ����Ѿ��̻�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�����������ز���ʶ����֪�˻��Ӻ�˵��";

        if (me->query_skill("chansi-shou", 1) < 1)
                return "������˿�����ֶ�ûѧ����̸���п��ԣ�";

        if (me->query("gongxian") < 400)
                return "��������ؤ����������Ϊ����������ʱ�����ܴ��㡣";

        if (me->query("shen") < 30000)
                return "����������»����ò�������������ʱ�����ܴ��㡣";

        if (me->query_skill("chansi-shou", 1) < 120)
                return "��Ĳ�˿�����ֻ�򻹲�����������ȥ���ߵ������ɡ�";

        if (me->query_skill("force") < 150)
                return "�����ڵ��ڹ���Ϊ���㣬�������ߵ������ɡ�";

        message_sort(HIY "\n$n" HIY "��Цһ��������һ�ӣ��漴ֻ����"
                     "˫�ֺ��ۺ�Ť����ץ��˦��ֱ��$N" HIY "����Ҫ��"
                     "��$N" HIY "��״���ɴ󾪣���æ�����ұܣ��мܲ�"
                     "�⣬��ʼ��δ�ܰ���$n" HIY "�ľ�����������Ϊ��"
                     "����\n\n" NOR, me, this_object()); 

        command("say ������ô��");
        tell_object(me, HIC "��ѧ���ˡ���˿���á���\n" NOR);
        if (me->can_improve_skill("hand"))
                me->improve_skill("hand", 1500000);
        if (me->can_improve_skill("chansi-shou"))
                me->improve_skill("chansi-shou", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/chansi-shou/qin", 1);
        me->add("gongxian", -400);

        return 1;
}
