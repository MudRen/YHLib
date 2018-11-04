#include <ansi.h>
#include "xueshan.h"

inherit NPC;
inherit F_MASTER;

mixed ask_skill1();

void create()
{
        set_name("����", ({ "huo du", "huo", "du" }));
        set("long", @LONG
���ǽ��ַ������µĶ����ӡ���÷������洫��
������Ϊ�ɹ����ӣ���λ�������
LONG);
        set("nickname", HIY "�ɹ�����" NOR);
        set("gender", "����");
        set("age", 31);
        set("attitude", "peaceful");
        set("shen_type", -1);

        set("str", 35);
        set("int", 20);
        set("con", 25);
        set("dex", 20);

        set("max_qi", 3200);
        set("max_jing", 2200);
        set("neili", 3800);
        set("max_neili", 3800);
        set("jiali", 120);
        set("combat_exp", 800000);

        set_skill("force", 180);
        set_skill("mizong-neigong", 180);
        set_skill("dodge", 160);
        set_skill("shenkong-xing", 160);
        set_skill("dagger", 180);
        set_skill("finger", 180);
        set_skill("poxu-daxuefa", 180);
        set_skill("sword", 160);
        set_skill("mingwang-jian", 160);
        set_skill("hand", 160);
        set_skill("dashou-yin", 160);
        set_skill("cuff", 160);
        set_skill("yujiamu-quan", 160);
        set_skill("parry", 160);
        set_skill("lamaism", 180);
        set_skill("literate", 100);
        set_skill("sanscrit", 100);
        set_skill("martial-cognize", 160);

        map_skill("force", "mizong-neigong");
        map_skill("dodge", "shenkong-xing");
        map_skill("parry", "poxu-daxuefa");
        map_skill("sword", "mingwang-jian");
        map_skill("dagger", "poxu-daxuefa");
        map_skill("finger", "poxu-daxuefa");
        map_skill("hand", "dashou-yin");
        map_skill("cuff", "yujiamu-quan");

        prepare_skill("finger", "poxu-daxuefa");

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "finger.tong" :),
                (: exert_function, "recover" :),
        }));

        create_family("������", 2, "����");

        set("inquiry", ([
                "��Ԫͨ��" : (: ask_skill1 :),
        ]));

        setup();

        carry_object("/d/xueshan/obj/gushan")->wield();
        carry_object("/d/city/npc/cloth/fu-cloth")->wear();
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((string)ob->query("gender") == "Ů��")
        {
                command("say �٣���һ�������ܵ�����������ʲô��");
                return;
        }

        if ((string)ob->query("gender") != "����")
        {
                command("say ��ƽ�������᲻�в�Ů�����ˣ����ҹ�����");
                return;
        }

        if ((string)ob->query("class") != "bonze")
        {
                command("say �����³���������ȫ���������ȻҲ����������");
                return;
        }

        if ((int)ob->query("shen") > -5000)
        {
                command("say �Ҵ�������������ʿ�򽻵������ҹ�����");
                return;
        }

        if ((int)ob->query_skill("mizong-neigong", 1) < 50)
        {
                command("say ���ڹ���ô�Ҳ����˼���鷳�ң�");
                return;
        }

        command("nod");
        command("say С���������㣬�Ժ�͸����Ұɡ�");
        command("recruit " + ob->query("id"));
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/poxu-daxuefa/tong"))
                return "����С�������Ѿ��̹�����ô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "���ҹ�����";

        if (me->query_skill("poxu-daxuefa", 1) < 1)
                return "���������Ѩ����ûѧ����С������ʲô��";

        if (me->query("gongxian") < 400)
                return "��Ϊ������Ч��������������ʱ�����ܴ��㡣";

        if (me->query("shen") > -10000)
                return "�٣���Ϊ��������ɣ��������в��ʺ��㡣";

        if (me->query_skill("force") < 160)
                return "����ڹ���Ϊ���㣬��ѧ������һ�С�";

        if (me->query_skill("poxu-daxuefa", 1) < 120)
                return "����������Ѩ��������������С���ɡ�";

        message_sort(HIY "\n$n" HIY "��˼Ƭ�̣����ŵ��˵�ͷ�����ֽ�$N" HIY
                     "������ߣ�������$P" HIY "���Ե���ϸ˵���ã�$N" HIY
                     "���󲻽����ĵ�һЦ���ƺ���$n" HIY "�Ľ̵���������"
                     "��\n\n" NOR, me, this_object());

        command("grin");
        command("say ���еľ��趼�������ˣ��ɵ�������ϰ��");
        tell_object(me, HIC "��ѧ���ˡ���Ԫͨ�项��\n" NOR);

        if (me->can_improve_skill("dagger"))
                me->improve_skill("dagger", 1500000);
        if (me->can_improve_skill("finger"))
                me->improve_skill("finger", 1500000);
        if (me->can_improve_skill("poxu-daxuefa"))
                me->improve_skill("poxu-daxuefa", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/poxu-daxuefa/tong", 1);
        me->add("gongxian", -400);

        return 1;
}
