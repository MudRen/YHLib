#include <ansi.h>;
#include "etc.h"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;

mixed ask_me();
mixed ask_skill();

void create()
{
        set_name("ɣ����", ({ "sang tugong", "sang", "tugong"}));
        set("gender", "����");
        set("title", "�������׶�����");
        set("age", 58);
        set("long", @LONG
����Ǵ������׶�������ɣ������ֻ�������
��С���뷢�԰ס��ֳ�һ����ͭ������������
��һ����ɣ���֣����Ǽ���С�ߡ����֮����
�ɣ�ͭ�̰�쵣�����һ�����
LONG );
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
    
        set("qi", 4200);
        set("max_qi", 4200);
        set("jing", 2000);
        set("max_jing", 2000);
        set("neili", 3800);
        set("max_neili", 3800);
        set("jiali", 100);
        set("combat_exp", 2000000);

        set_skill("force", 180);
        set_skill("shennong-xinjing", 180);
        set_skill("dodge", 200);
        set_skill("xuefu-mizong", 200);
        set_skill("strike", 180);
        set_skill("dusha-zhang", 180);
        set_skill("hand", 180);
        set_skill("lansha-shou", 180);
        set_skill("parry", 180);
        set_skill("staff", 180);
        set_skill("shennong-zhang", 180);
        set_skill("throwing", 220);
        set_skill("pidi-shenzhen", 220);
        set_skill("literate", 160);
        set_skill("poison", 200);
        set_skill("martial-cognize", 180);

        map_skill("force", "shennong-xinjing");
        map_skill("dodge", "xuefu-mizong");
        map_skill("strike", "dusha-zhang");
        map_skill("hand", "lansha-shou");
        map_skill("throwing", "pidi-shenzhen");
        map_skill("parry", "jiuqu-zhegufa");
        map_skill("staff", "shennong-zhang");

        prepare_skill("hand", "lansha-shou");
        prepare_skill("strike", "dusha-zhang");

        set("inquiry", ([
                "��ڽ���"   : (: ask_me :),
                "�öݺ���"   : (: ask_skill :),
                "����"       : "�����������չ��µ�����������ȫ���������",
                "������"     : "�����������չ��µ�����������ȫ���������",
        ]));

        create_family("���׶�", 8, "����");

        set("zhen_count", 3);

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "staff.lun" :),
                (: perform_action, "throwing.huan" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );

        setup();
        carry_object("/clone/weapon/gangzhang")->wield();
        carry_object("/clone/cloth/cloth")->wear();
        set_temp("handing", carry_object("/d/lingjiu/npc/obj/jinzhen"));
}

int recognize_apprentice(object ob, string skill)
{
        if (ob->query("family/family_name") != "���չ�")
        {
                command("bite");
                command("say �����������ҿ�ûʱ�����ġ�");
                return -1;
        }

        if (ob->query("family/master_id") != "xuzhu zi")
        {
                command("heng");
                command("say ����ʲô������������ʦ����Ҳ���������");
                return -1; 

        }

        if (skill != "pidi-shenzhen" && skill != "throwing")
        {
                command("say ����ֻ����һЩ�����ַ�����ѧ�����ˡ�");
                return -1;
        }

        if (skill == "throwing" && ob->query_skill("throwing", 1) > 179)
        {
                command("say �㰵���������Ѿ��ܸ��ˣ�ʣ�µľ��Լ�ȥ�о��ɡ�");
                return -1;
        }

        if (! ob->query_temp("can_learn/sangtugong"))
        {
                command("bored");
                command("say ���������������ķ��ϣ��ҽ�����ˡ�");
                ob->set_temp("can_learn/sangtugong", 1);
        }
        return 1;
}

mixed ask_skill()
{
        object me;

        me = this_player();
        if (me->query("can_perform/pidi-shenzhen/huan"))
                return "�Ҳ����Ѿ��̻�������";

        if (me->query("family/family_name") != "���չ�" &&
           me->query("family/family_name") != "���׶�")
                return "����ҹ������ҿ�ûʱ�����ġ�";

        if (me->query_skill("pidi-shenzhen", 1) < 1)
                return "��ٵ����붼ûѧ����̸ʲô���С�";

        if (me->query("family/family_name") == "���չ�" &&
           me->query("gongxian") < 600)
                return "�ţ�����˵���ˣ����ô������޹��͵ĵ��ӡ�";

        if (me->query_skill("force") < 200)
                return "����ڹ������������ôѧ������";

        if (me->query_skill("pidi-shenzhen", 1) < 140)
                return "��ıٵ������򻹲��Զ���ٻ�ȥ������";

        message_vision(HIY "$n" HIY "����һЦ����$N" HIY "������ǰ����"
                       "���ڶ�������˵��Щʲô������������\n�֣�ʮָ"
                       "���ţ�һ��һ������������һ�ֺ��ر�İ������š�\n"
                       NOR, me, this_object());

        command("grin");
        command("say �����ڴ�ܵ�ʱ��ܹ��ã����Ĩ���˶������ٺ١�");
        tell_object(me, HIC "��ѧ���ˡ��öݺ��ǡ���\n" NOR);
        if (me->can_improve_skill("throwing"))
                me->improve_skill("throwing", 1500000);
        if (me->can_improve_skill("pidi-shenzhen"))
                me->improve_skill("pidi-shenzhen", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/pidi-shenzhen/huan", 1);
        if (me->query("family/family_name") == "���չ�")
                me->add("gongxian", -600);
        return 1;
}

mixed ask_me()
{
        object me;
        object ob;

        me = this_player();

        if (me->query("family/family_name") != "���չ�" &&
           me->query("family/family_name") != "���׶�")
                return "�������ҿ�ûʱ�����ġ�";

        if (me->query("family/master_id") != "xuzhu zi")
                return "����ʦ�����ã��ⱦ���ɲ��������ˡ�";

        if (me->query_skill("pidi-shenzhen", 1) < 100)
                return "��ٵ�������ַ��������ң���������Ҳûʲô�á�";

        if (query("zhen_count") < 1)
                return "û�ˣ�û�ˣ����ϵ׶������Ƹɾ��ˡ�";

        add("zhen_count", -1);
        ob = new("/d/lingjiu/npc/obj/jinzhen");
        message_vision("$N�ó���ʮ��" HIR "��ڽ���" NOR "(Lanwu jinzhen)��$n��\n",
                       this_object(), me);
        ob->move(me, 1);
        return "���������ڽ���������ȥ�ðɡ�";
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        command("sigh2");
        command("say �����������ʲô�˶��У�������ô�����ɲ��ݣ�ȴ�������ҡ�");
        command("say ����Ҳ��ó�������Ȼ���ˣ��Ҿ�������ɡ�");
        command("recruit " + ob->query("id"));
}
