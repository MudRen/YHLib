#include <ansi.h>
#include "meizhuang.h"

#define QIPAN    "/clone/lonely/qipan"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;
inherit F_COAGENT;

mixed ask_skill1();
mixed ask_skill2();
mixed ask_skill3();
mixed ask_qipan();

void create()
{
        object ob;
        set_name("�ڰ���", ({ "heibai zi", "hei", "bai", "heibai", "zi" }));
        set("long", @LONG
����һλ���߼��ݵĺ������ߣ������÷ׯ��
λׯ�����еڶ��ĺڰ��ӡ�����ü��Ŀ�㣬ֻ
����ɫ���ף��ƺ���һ�߽�ʬģ��������һ��
֮�£����б�е�һ�����⡣��ͷ�����ڶ�Ƥ
�����ף���Ȼ�Ǻڰ׷�����
LONG);
        set("title", "÷ׯ��ׯ��");
        set("nickname", HIR "÷ׯ����" NOR);
        set("gender", "����");
        set("age", 58);
        set("attitude", "peaceful");
        set("str", 35);
        set("int", 35);
        set("con", 35);
        set("dex", 35);

        set("max_qi", 5000);
        set("max_jing", 4500);
        set("neili", 5500);
        set("max_neili", 5500);
        set("jiali", 200);
        set("combat_exp", 2500000);

        set_skill("force", 220);
        set_skill("wuzheng-xinfa", 200);
        set_skill("xuantian-wujigong", 220);
        set_skill("dodge", 220);
        set_skill("meihua-zhuang", 220);
        set_skill("parry", 220);
        set_skill("hammer", 240);
        set_skill("finger", 240);
        set_skill("xuantian-zhi", 240);
        set_skill("fenglei-panfa", 240);
        set_skill("strike", 200);
        set_skill("qingmang-zhang", 200);
        set_skill("literate", 200);
        set_skill("fenglei-zifa", 240);
        set_skill("throwing", 240);
        set_skill("chess", 280);
        set_skill("martial-cognize", 220);

        map_skill("force", "xuantian-wujigong");
        map_skill("dodge", "meihua-zhuang");
        map_skill("parry", "fenglei-panfa");
        map_skill("hammer", "fenglei-panfa");
        map_skill("strike", "qingmang-zhang");
        map_skill("throwing", "fenglei-zifa");
        map_skill("finger", "xuantian-zhi");

        prepare_skill("finger", "xuantian-zhi");

        create_family("÷ׯ", 1, "ׯ��");

        set("inquiry", ([
                "����"        : "��Ҫ��ʲô���У�",
                "����"        : "��Ҫ��ʲô������",
                "������"      : "����������������ϴ������������Ѿ�ʧ�ٺܾ��ˡ�",
                "��������"    : "���������书��ɲ⣬�����޵С�",
                "�������"    : "����÷ׯ���Ѻ�����������޹ϸ�������������",
                "ŻѪ��"      : "���Ǵ�˵�еĶ��������������ڡ�",
                "���վ�"      : (: ask_skill1 :),
                "�����Ļ�"    : (: ask_skill2 :),
                "�������"    : (: ask_skill3 :),
                "��������"    : (: ask_qipan :),
        ]));

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "hammer.fenglei" :),
                (: perform_action, "throwing.she" :),
                (: perform_action, "finger.bing" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),

        }));

        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        setup();

        if (clonep())
        {
                ob = find_object(QIPAN);
                if (! ob) ob = load_object(QIPAN);
                if (! environment(ob))
                {
                        ob->move(this_object());
                        ob->wield();
                } else
                {
                        ob = new("/d/meizhuang/obj/qipan");
                        ob->move(this_object());
                        ob->wield();
                }
        }
        carry_object("clone/misc/cloth")->wear();
        set_temp("handing", carry_object("/d/meizhuang/obj/qizi"));
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
                command("ah");
                command("say ԭ���Ƕ��������ĵ��ӣ����㡭�����ûʲô���⡣");
                command("say ����������֮ǰ���ҵ��ȿ���һ�����������");
                me->set("move_party/������̡�÷ׯ", 1);
        }

        if ((int)me->query("combat_exp") < 200000)
        {
                command("sigh");
                command("say ��Ľ�������̫ǳ�������ȶ����������˵�ɡ�");
                return;
        }

        if ((int)me->query_skill("force") < 120)
        {
                command("say ���ڹ����̫����������㣬Ҳ������ʲô��Ϣ��");
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

        if (me->query("can_perform/fenglei-zifa/she"))
                return "���Ѿ��̹����ˣ��Լ���ȥ���������Ǹ��Ҿ������ݡ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ������޹ϸ𣬺γ����ԣ�";

        if (me->query_skill("fenglei-zifa", 1) < 1)
                return "���������ӷ���ûѧ����̸���ԣ�";

        if (me->query("gongxian") < 300)
                return "��Ա�ׯ�������Ĺ��ײ�������һ������ʱ�����ܴ��㡣";

        if (me->query_skill("fenglei-zifa", 1) < 100)
                return "��ķ����ӷ������ò����ң��Լ���ȥ���������ɣ�";

        message_vision(HIY "$n" HIY "΢΢һЦ����������һ�����ӣ���쬡���"
                       "�����˳�ȥ��$N" HIY "ֻ����ǰһ�����ǿ��������ô�"
                       "\n���Լ��Ÿ�ǰ����ש�ϣ�û����֮�\n" NOR, me,
                       this_object());
        command("nod");
        command("say ��һ�б��Ƿ����ӷ������գ��㿴�����˶��٣�");
        tell_object(me, HIC "��ѧ���ˡ����վ�����\n" NOR);

        if (me->can_improve_skill("throwing"))
                me->improve_skill("throwing", 1500000);
        if (me->can_improve_skill("fenglei-zifa"))
                me->improve_skill("fenglei-zifa", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/fenglei-zifa/she", 1);
        me->add("gongxian", -300);

        return 1;
}

mixed ask_skill2()
{
        object me;

        me = this_player();

        if (me->query("can_perform/fenglei-panfa/fenglei"))
                return "���Ѿ��̹����ˣ��Լ���ȥ���������Ǹ��Ҿ������ݡ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ������޹ϸ𣬺γ����ԣ�";

        if (me->query_skill("fenglei-panfa", 1) < 1)
                return "���������̷���ûѧ����̸���ԣ�";

        if (me->query("gongxian") < 1000)
                return "��Ա�ׯ�������Ĺ��ײ�������һ������ʱ�����ܴ��㡣";

        if (me->query_skill("force") < 200)
                return "����ڹ�����в�������ѧ������һ�С�";

        if (me->query_skill("fenglei-panfa", 1) < 150)
                return "��ķ����̷������ò����ң��Լ���ȥ���������ɣ�";

        message_vision(HIY "$n" HIY "���˵�ͷ����$N" HIY "����"
                       "��ߣ��ڶ��Ե���ϸ˵���ã�$N" HIY "����"
                       "���죬��Ȼ˵�������������ˣ���ν��\n��"
                       "����̧���Ƽ��硢���������ꡢ����������"
                       "���������������\n" NOR, me, this_object());

        command("haha");
        command("say ������������Ƿ����Ļ��İ��أ����Լ���ȥ���ɡ�");
        tell_object(me, HIC "��ѧ���ˡ������Ļ�����\n" NOR);

        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("hammer"))
                me->improve_skill("hammer", 1500000);
        if (me->can_improve_skill("fenglei-panfa"))
                me->improve_skill("fenglei-panfa", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/fenglei-panfa/fenglei", 1);
        me->add("gongxian", -1000);

        return 1;
}

mixed ask_skill3()
{
        object me;

        me = this_player();

        if (me->query("can_perform/xuantian-zhi/bing"))
                return "���Ѿ��̹����ˣ��Լ���ȥ���������Ǹ��Ҿ������ݡ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ������޹ϸ𣬺γ����ԣ�";

        if (me->query_skill("xuantian-zhi", 1) < 1)
                return "��������ָ��ûѧ����̸���ԣ�";

        if (me->query("gongxian") < 1500)
                return "��Ա�ׯ�������Ĺ��ײ�������һ������ʱ�����ܴ��㡣";

        if (me->query_skill("xuantian-wujigong", 1) < 180)
                return "��������޼�����򲻹���ѧ������һ�С�";

        if (me->query_skill("xuantian-zhi", 1) < 180)
                return "�������ָ�����ò����ң��Լ���ȥ���������ɣ�";

        message_vision( HIW "$n" HIW "���˵�ͷ��Ĭ�������޼������������"
                       "ʳָ���������ϵĻ�ƿ\n�С�Ƭ�̼仨ƿˮ��㸡��һ"
                       "˿˿������������ʱ��ƿ��������һ��\n���䣬����ˮ"
                       "����һƬƬ��������Խ��Խ��ֻһյ��ʱ�֣�����"
                       "\n��ƿ�ڵ���ˮ�������˺�����\n" NOR, me,
                       this_object());
        command("nod");
        command("say ���������ָ��������������˹����ţ����Լ���ȥ���ɡ�");
        tell_object(me, HIC "��ѧ���ˡ������������һ�С�\n" NOR);

        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("xuantian-wujigong"))
                me->improve_skill("xuantian-wujigong", 1500000);
        if (me->can_improve_skill("finger"))
                me->improve_skill("finger", 1500000);
        if (me->can_improve_skill("xuantian-zhi"))
                me->improve_skill("xuantian-zhi", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/xuantian-zhi/bing", 1);
        me->add("gongxian", -1500);

        return 1;
}

mixed ask_qipan()
{
        object me;
        object ob;

        me = this_player();

        if (me->query("family/family_name") != "÷ׯ")
                return "��ͱ�ׯ����ԨԴ����������ʲô��";

        if (me->query("family/master_id") != query("id"))
                return "ֻ���ҵĵ��Ӳ���ʹ�����������̡�";

        if (me->query_skill("fenglei-panfa", 1) < 150)
                return "�㻹����ȥ����ķ����̷����������ɡ�";

        if (me->query_skill("chess", 1) < 100)
                return "�������嶼���ᣬ�����ⱦ�����";

        if (present("xuantie qipan", me))
                return "�����������̲���������������ô���Ǹ��Ҿ������ݣ�";

        ob = present("xuantie qipan", this_object());

        if (! objectp(ob))
                return "�������������Ѿ������������ˡ�";

        ob->move(this_object());
        command("give xuantie qipan to " + me->query("id"));

        ob = new("/d/meizhuang/obj/qipan");
        ob->move(this_object());
        ob->wield();

        return "�ܺã���Ȼ�����������������������ʱ��ȥ�ðɡ�";
}

int accept_object(object me, object ob)
{
        int r;
        if (r = ::accept_object(me, ob))
                return r;

        if (base_name(ob) != QIPAN)
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

void unconcious()
{
        die();
}
