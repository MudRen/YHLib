// yang.c ���

inherit NPC;
inherit F_MASTER;
inherit F_GUARDER;

#include <ansi.h>
#include "gumu.h"

string ask_yunv();
int not_to_learn_ss(object ob);
mixed teach_sad();

void create()
{
        set_name("���", ({"yang guo", "yang"}));
        set("gender", "����");
        set("age", 26);
        set("long", @LONG
������ȥüĿ֮����һ������֮����Ȼ������ԼԼȴ���˸е�һ����֮�飬
����յ����ģ���Ȼ���ǲм���
LONG );
        set("attitude", "friendly");

        set("str", 35);
        set("int", 36);
        set("con", 34);
        set("dex", 32);

        set("qi", 7800);
        set("max_qi", 7800);
        set("jing", 6900);
        set("max_jing", 6900);
        set("neili", 8500);
        set("max_neili", 8500);
        set("jiali", 120);

        set("combat_exp", 5750000);

        set("couple/id", "xiao longnv");
        set("couple/name", "С��Ů");

        set_skill("force", 390);
        set_skill("yunv-xinfa", 390);
        set_skill("surge-force", 390);
        set_skill("sword", 380);
        set_skill("yunv-jian", 380);
        set_skill("quanzhen-jian", 380);
	set_skill("xuantie-jian", 380);
        set_skill("dodge", 350);
        set_skill("yunv-shenfa", 350);
        set_skill("parry", 385);
        set_skill("unarmed", 385);
        set_skill("meinv-quan", 370);
        set_skill("strike", 380);
        set_skill("sad-strike", 380);
        set_skill("fireice-strike", 380);
        set_skill("tianluo-diwang", 360);
        set_skill("literate", 250);
        set_skill("taoism", 300);
	set_skill("medical", 380);
	set_skill("yunv-xinjing", 380);
        set_skill("throwing", 340);
        set_skill("yufeng-zhen", 340);
        set_skill("martial-cognize", 300);

        map_skill("force", "surge-force");
        map_skill("sword", "xuantie-jian");
        map_skill("dodge", "yunv-shenfa");
        map_skill("parry", "meinv-quan");
        map_skill("unarmed", "sad-strike");
        map_skill("strike", "tianluo-diwang");

        prepare_skill("unarmed", "sad-strike");

        create_family("��Ĺ��", 3, "����");

        set("inquiry", ([
                "������" : "��...�٣�",
	        "����"   : "�������������Ĵ�����",
		"����"   : "��ʦ��ô...�治��˵����",
		"С��Ů" : "����������Ӹ�ʲô��",
		"�"   : "���ˣ�������Ҳ�ա�",
                "�����" : "����ͷ��û�У��ܾ�û�������ˡ�",
                "��Ȼ������" : (: teach_sad :),
                "��������"   : "���Ƕ���ǰ��������ѧ���������ҵ���ϰ�ã�\n",
        ]));

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
	        (: perform_action, "strike.wang" :),
	        (: perform_action, "unarmed.xiao" :),
	        (: perform_action, "unarmed.tuo" :),
	        (: exert_function, "recover" :),
	        (: exert_function, "powerup" :),
        }));

        set_temp("apply/attack", 150);
        set_temp("apply/defense", 150);
        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        setup();

        carry_object("/clone/cloth/qingyi")->wear();
}

mixed teach_sad()
{
        object ob = this_player();

        if (ob->query_skill("sad-strike", 1) >= 1)
        {
                command("say �㲻���Ѿ�������");
                return 1;
        }

        if (ob->query("gender") != "����")
        {
                command("say �������书ֻ�ʺ������������㻹�����˰ɣ�");
                return 1;
        }

        if (ob->query("static/sadly") < 3)
        {
                command("say ����᲻������˼�����ӵ��黳��"
                        "�޷�����ҵ���Ȼ�����ƣ�");
                return 1;
        }

        if (ob->query("character") == "���ռ�թ" || 
            ob->query("character") == "�ĺ�����")
        {
                command("say ��һ������ȥ���ˣ��޷�������Ȼ����ľ��磡");
                return 1;
        }

        if (ob->query("int") < 34)
        {
                command("say ���������Բ��㣬�޷�������Ȼ�����ơ�");
                return 1;
        }

        if (ob->query("str") < 34)
        {
                command("say ������������㣬�޷�������Ȼ�����ơ�");
                return 1;
        }

        if ((int)ob->query("max_neili") < 3000)
        {
                command("say ���������Ϊ���㣬�޷�����Ȼ�����ơ�");
                return 1;
        }

        if (ob->query_skill("force") < 320)
        {
                command("say ���ڹ���Ϊ���㣬�޷�������Ȼ�����ơ�");
                return 1;
        }                

        if ((int)ob->query_skill("unarmed", 1) < 200)
        {
                command("say ��Ļ���ȭ�Ų�����죬�޷�����Ȼ�����ơ�");
                return 1;

        }

        if (ob->query_skill("martial-cognize", 1) < 200)
        {
                command("say ����ѧ�������㣬�޷���������Ȼ�����ơ�");

                return 1;
        }

        message_vision(HIW "$n" HIW "���˿�$N" HIW "�������ã�����Ҳ��������"
                       "ԨԴ���Ҿʹ�����Ȼ�����ƣ�\n" NOR, ob, this_object());

        ob->set_skill("sad-strike", 10);

        tell_object(ob, HIG "��ѧ���ˡ���Ȼ�����ơ���\n" NOR);
 
        command("tan");
        command("say ��ȥ��ϰ�ɣ��ǵ�Ҫ�úöԴ�������ӣ�");

        return 1;
}

int accept_ask(object me, string topic)
{
        switch (topic)
        {

        case "���־�" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/xuantie-jian/juan",
                           "free"    : 1,
                           "name"    : "���־�",
                           "sk1"     : "xuantie-jian",
                           "lv1"     : 100,
                           "neili"   : 3000,
                           "force"   : 400,
                        ]));
                break;

        case "�󽭶�ȥ" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/xuantie-jian/dong",
                           "free"    : 1,
                           "name"    : "�󽭶�ȥ",
                           "sk1"     : "xuantie-jian",
                           "lv1"     : 200,
                           "neili"   : 5000,
                           "force"   : 400,
                         ]));
                break;

        case "��Ȼ����" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/sad-strike/xiao",
                           "free"    : 1,
                           "name"    : "��Ȼ����",
                           "sk1"     : "sad-strike",
                           "lv1"     : 150,
                           "neili"   : 3200,
                           "force"   : 320,
                         ]));
                break;

        case "�����ˮ" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/sad-strike/tuo",
                           "free"    : 1,
                           "name"    : "�����ˮ",
                           "sk1"     : "sad-strike",
                           "lv1"     : 180,
                           "neili"   : 4000,
                           "force"   : 360,
                         ]));
                break;

        default:
                return 0;
        }
}

void unconcious()
{
        die();
}
