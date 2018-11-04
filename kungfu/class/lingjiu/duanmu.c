#include <ansi.h>;
#include "etc.h"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;

mixed ask_me();

void create()
{
        set_name("��ľԪ", ({ "duanmu yuan", "duanmu", "yuan"}));
        set("gender", "����");
        set("title", "���ϵ����涴����");
        set("nickname", HIR "��ȥ����" NOR);
        set("age", 54);
        set("long", @LONG
���ͷ���߾��Ǻ��ϵ���ָɽ���涴������ľ
Ԫ��ֻ����һ�Ŵ��Դ���ͺͺ�أ����ͷ��Ҳ
�ޣ�������Ѫ��ԶԶ��ȥ�������Ѫ��㡣
LONG );
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
    
        set("qi", 4000);
        set("max_qi", 4000);
        set("jing", 1800);
        set("max_jing", 1800);
        set("neili", 4200);
        set("max_neili", 4200);
        set("jiali", 120);
        set("combat_exp", 2200000);

        set_skill("force", 200);
        set_skill("wudoumi-shengong", 200);
        set_skill("dodge", 180);
        set_skill("feiyan-zoubi", 180);
        set_skill("unarmed", 200);
        set_skill("parry", 200);
        set_skill("martial-cognize", 180);
        set_skill("literate", 140);

        map_skill("dodge", "feiyan-zoubi");
        map_skill("force", "wudoumi-shengong");
        map_skill("parry", "wudoumi-shengong");
        map_skill("unarmed", "wudoumi-shengong");

        prepare_skill("unarmed", "wudoumi-shengong");

        set("inquiry", ([
                "��ȥ����"   : (: ask_me :),
                "�嶷����" : "�⡭������������ɵػ��ݻ�������һ�Ź���",
                "�ػ�"     : "�ػ����Һ��ϵ���ָɽ���涴һ�ɵĻ�������",
                "������"     : "�����������չ��µ�����������ȫ���������",
                "����"       : "�����������չ��µ�����������ȫ���������",
        ]));

        create_family("���涴", 14, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.gui" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );

        setup();
        carry_object("/clone/cloth/cloth")->wear();
}

int recognize_apprentice(object ob, string skill)
{
        if (ob->query("family/family_name") != "���չ�")
        {
                command("?");
                command("say �������������Ĺ�����");
                return -1;
        }

        if (ob->query("family/master_id") != "xuzhu zi")
        {
                command("grin");
                command("say ���������չ�����ֲ�����˵���ɣ�");
                return -1; 

        }

        if (skill != "wudoumi-shengong" && skill != "unarmed")
        {
                command("say ��ֻ�������嶷���񹦺�һЩȭ��֪ʶ����ѧ�����ˡ�");
                return -1;
        }

        if (skill == "unarmed" && ob->query_skill("unarmed", 1) > 179)
        {
                command("sweat");
                command("say ���ˣ����ˣ��������ˣ�ʣ�µ����Լ�ȥ�о���");
                return -1;
        }

        if (! ob->query_temp("can_learn/duanmuyuan"))
        {
                command("sigh");
                command("say �������Ȼ�������������ģ���Ҳֻ�н�����ˡ�");
                ob->set_temp("can_learn/duanmuyuan", 1);
        }
        return 1;
}

mixed ask_me()
{
        object me;

        me = this_player();
        if (me->query("can_perform/wudoumi-shengong/gui"))
                return "�������Ѿ�˵�ù����ˣ��Լ���ȥ���ɡ�";

        if (me->query("family/family_name") != "���չ�" &&
           me->query("family/family_name") != "���涴")
                return "���������Ĺ��������������������";

        if (me->query_skill("wudoumi-shengong", 1) < 1)
                return "�٣���ѧ�����������嶷������";

        if (me->query("family/family_name") == "���չ�" &&
           me->query("gongxian") < 1500)
                return "�ţ�����˵���ˣ����ô������޹��͵ĵ��ӡ�";

        if (me->query_skill("force") < 200)
                return "�㿴�㣬�ڹ�������������ʲô����";

        if ((int)me->query("max_neili", 1) < 2000)
                return "�������������������ôѧϰ��ȥ���⣿";

        if (me->query_skill("wudoumi-shengong", 1) < 140)
                return "����嶷���񹦻�򻹲��Զ���ٻ�ȥ������";

        message_vision(HIY "$n" HIY "���˵�ͷ��һ�����ԣ�����$N" HIY "�³�"
                       "һ��Ũ̵��$N" HIY "����\n��������������������ʱ"
                       "ȴ���ǿ�Ũ̵��$N" HIY "���ת�˸�\n�䣬�ַ��˻�����"
                       "��ֱ����$N" HIY "�ĺ����ϡ�\n" NOR, me,
                       this_object());
        command("haha");
        command("say ���������ⶫ�������ý�����Ҫ�໨Щ����");
        command("say ���о��ǣ�ʩ��ǰҪ��ȫ�����������������ŵ���Ӧ�֡�");
        tell_object(me, HIC "��ѧ���ˡ���ȥ���⡹��\n" NOR);
        tell_object(me, HIC "��ѧ������ν��嶷������Ϊȭ��ʩչ��\n" NOR);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", 1500000);
        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", 1500000);
        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", 1500000);
        if (me->can_improve_skill("wudoumi-shengong"))
                me->improve_skill("wudoumi-shengong", 1500000);
        if (me->can_improve_skill("wudoumi-shengong"))
                me->improve_skill("wudoumi-shengong", 1500000);
        if (me->can_improve_skill("wudoumi-shengong"))
                me->improve_skill("wudoumi-shengong", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/wudoumi-shengong/gui", 1);
        if (me->query("family/family_name") == "���չ�")
                me->add("gongxian", -1500);
        return 1;
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        command("@@");
        command("say �㡭��û���ɣ���Ȼ��������������Һ��ˡ�");
        command("recruit " + ob->query("id"));
}

void unconcious()
{
        die();
}
