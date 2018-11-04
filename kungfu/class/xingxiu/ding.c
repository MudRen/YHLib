// ding.c ������

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;
inherit F_QUESTER;

#include "xingxiu.h"
#include <ansi.h>

string ask_me();
string ask_du1();
string ask_du2();
string ask_xiangliao();

#define SUO "/clone/lonely/rousisuo"

void create()
{
        set_name("������", ({ "ding chunqiu", "ding" }));
        set("nickname", HIG "�����Ϲ�" NOR);
        set("long", @LONG
�����������ɿ�ɽ��ʦ����������ʿ���ʹ���������Ϲֶ����
��������������ò���棬�ɷ���ǡ�
LONG );
        set("gender", "����");
        set("age", 60);
        set("attitude", "friendly");
        set("class", "scholar");
        set("shen_type", -1);
        set("str", 25);
        set("int", 30);
        set("con", 38);
        set("dex", 38);
        
        set("max_qi", 6400);
        set("max_jing", 2900);
        set("neili", 7300);
        set("max_neili", 7300);
        set("jiali", 120);
        set("combat_exp", 3850000);

        set_skill("force", 260);
        set_skill("huagong-dafa", 260);
        set_skill("guixi-gong", 260);
        set_skill("throwing", 240);
        set_skill("feixing-shu", 240);
        set_skill("dodge", 240);
        set_skill("zhaixing-gong", 240);
        set_skill("strike", 260);
        set_skill("chousui-zhang", 260);
        set_skill("claw", 240);
        set_skill("sanyin-wugongzhao", 240);
        set_skill("whip", 240);
        set_skill("chanhun-suo", 240);
        set_skill("parry", 240);
        set_skill("staff", 240);
        set_skill("poison", 260);
        set_skill("tianshan-zhang", 240);
        set_skill("literate", 200);
        set_skill("medical", 260);
        set_skill("xingxiu-qishu", 260);

        map_skill("force", "huagong-dafa");
        map_skill("dodge", "zhaixing-gong");
        map_skill("strike", "chousui-zhang");
        map_skill("claw", "sanyin-wugongzhao");
        map_skill("whip", "chanhun-suo");
        map_skill("parry", "tianshan-zhang");
        map_skill("staff", "tianshan-zhang");
        map_skill("poison", "xingxiu-qishu");
        map_skill("throwing", "feixing-shu");

        prepare_skill("strike", "chousui-zhang");
        prepare_skill("claw", "sanyin-wugongzhao");

        set("book_count", 1);
        set("zhen_count", 1);
        set("san_count", 1);
        set("xiangliao_count", random(10) + 10);

        set("inquiry", ([
                "����"       : (: ask_me :),
                "���޶���"   : (: ask_me :),
                "������"     : (: ask_du1 :),
                "����"       : (: ask_xiangliao :),
                "��ң��Цɢ" : (: ask_du2 :),
                "��ľ����"   : "�ߣ������������ע�⣬С����һ�Ʊ��ˣ�\n",
        ]));

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                //(: perform_action, "staff.fugu" :),
                //(: perform_action, "staff.xue" :),
                //(: perform_action, "strike.tao" :),
                (: perform_action, "strike.dan" :),
                (: perform_action, "strike.tao" :),
                (: perform_action, "strike.shi" :),
                (: perform_action, "claw.zhua" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        create_family("������", 1, "��ɽ��ʦ");
        set("class", "taoist");

        set_temp("apply/damage", 180);
        set_temp("apply/armor", 400);
        set_temp("apply/attack", 250);
        set_temp("apply/dodge", 250);
        set_temp("apply/parry", 250);

        setup();
        //carry_object("/clone/weapon/gangzhang")->wield();
        carry_object("/clone/cloth/cloth")->wear();
        //set_temp("handing", carry_object("/clone/misc/duwan"));

}

void init()
{
        object me;

        me = this_player();

        if (! interactive(me))
                return;

        if (living(this_object()) && present("shenmuwang ding", me))
        {
                command("say �üһԭ����͵���ҵ���ľ�����������ɣ�");
                kill_ob(me);
                return;
        }

        add_action("do_flatter", "flatter");
}

void attempt_apprentice(object me)
{

        if ((int)me->query("shen") > -12000)
        {
                command("say ������Խ����Խ��׵������Ե׵ġ�");
                return;
        }

        if ((int)me->query("combat_exp") < 300000)
        {
                command("say �����΢ĩ���������ѧ�����ɵ������");
                return;
        }

        if (me->query_skill("chousui-zhang", 1) < 120)
        {
                command("say ������ƶ�û��������Ȼ�����������ң�");
                return;
        }

        if ((int)me->query_skill("poison", 1) < 120)
        {
                command("say �㶾����ûѧ���ף������������ң�");
                return;
        }

        if( me->query_temp("pending/flatter"))
        {
                command("say ����˲������ɷ�����������������㣿");
                return;
        } else
        {
                command("say ���������ɱ������������ʥ����ô������");
                message_vision("�����Ϲ�΢��˫�ۣ������룬һ����������(flatter)�����ӡ�\n",
                this_player());
                me->set_temp("pending/flatter", 1);
        }
}

int do_flatter(string arg)
{
        if (! this_player()->query_temp("pending/flatter"))
                return 0;

        if (! arg) return notify_fail("��˵����ʲô��\n");
        this_player()->set_temp("pending/flatter", 0);
        message_vision("$N����˵����" + arg + "\n", this_player());
        if( strsrch(arg, "��������") >=0 && (strsrch(arg, "�������") >=0
         || strsrch(arg, "�������") >=0 || strsrch(arg, "�Ž��ޱ�") >=0 )) {
                command("smile");
                command("say �⻹��ࡣ\n");
                welcome(this_player());
                command("recruit " + this_player()->query("id"));
        } else
        {
                command("say ����˲����ҷ���������������㣿");
        }
        return 1;
}

// �������ɣ�������أ��������Ž��ޱ�
string ask_me()
{
        mapping fam; 
        object ob;
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
                return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��\n";

        if (query("book_count") < 1)
                return "�������ˣ����ɵ��ڹ��ķ����ڴ˴���\n";

        add("book_count", -1);
        ob = new("/clone/book/dujing_2");
        ob->move(this_player());
        return "�ðɣ��Ȿ�����޶��������û�ȥ�ú����С�\n";
}

string ask_du1()
{
        mapping fam; 
        object ob;
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
                return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��\n";

        if (this_player()->query_skill("poison", 1) < 50)
                return "��Ķ������δ�����ò������ֶ�����\n";

        if (query("zhen_count") < 1)
                return "�������ˣ������붼�����ˡ�\n";

        add("zhen_count", -1);
        ob = new("/d/xingxiu/obj/bilinzhen");
        ob->move(this_player());
        return "�ðɣ������������Щ��ɡ�\n";
}

string ask_du2()
{
        mapping fam; 
        object ob;
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
                return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��\n";

        if (this_player()->query_skill("poison", 1)<100)
                return "��Ķ������δ�����ò������ֶ�����\n";

        if (query("san_count") < 1)
                return "�������ˣ�����ûʲôʣ���ˡ�\n";

        add("san_count", -1);
        ob = new("/d/xingxiu/obj/sanxiaosan");
        ob->move(this_player());
        return "�ðɣ������ҩ���û�ȥ�Ƽ����ðɡ�\n";
}

string ask_xiangliao()
{
        mapping fam;
        object ob;

        if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
                return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��\n";

        if (is_busy() || is_fighting())
                return "�Ȼ����û��������æ����ô��\n";

        if (this_player()->query_temp("get_xiangliao"))
                return "�ղŲ��Ǹ������𣿲�����ô��������˰ɣ�\n";

        if (this_player()->query_skill("poison", 1) < 40)
                return "��Ķ������̫�����������˵�ɣ�\n";

        if (query("xiangliao_count") < 1)
                return "�������ˣ�����ûʲôʣ�µ������ˣ��㻹��ȥ�ֿ����ҿ��ɣ�\n";

        add("xiangliao_count", -1);
        ob = new("/clone/misc/xiangliao");
        ob->set_amount(random(50) + 100);
        ob->move(this_player());
        start_busy(2);
        this_player()->set_temp("get_xiangliao", 1);
        call_out("clear_xiangliao_flag", 180);
        return "�ðɣ���Щ��������ȥ�����ðɡ�\n";
}

void reset()
{
        set("xiangliao_count", random(10) + 10);
}

void unconcious()
{
        die();
}

int accept_ask(object me, string topic)
{
        switch(topic)
        {
             case "����" :
             case "����" :
             case "����" :
                 return QUEST_D->accept_ask(this_object(), me, topic);

             case "�����":
                 return MASTER_D->teach_pfm(me, this_object(),
                               (["perform"  :  "can_perform/chanhun-suo/duo",
                                 "name"     :  "�����",
                                 "sk1"      :  "chanhun-suo",
                                 "lv1"      :  100,
                                 "sk2"      :  "force",
                                 "lv2"      :  130,
                                 "shen"     :  -10000,
                                 "gongxian" :  80,
                                 "force"    :  80 ]));
                  break;

             case "���ĵ�":
                 return MASTER_D->teach_pfm(me, this_object(),
                               (["perform"  :  "can_perform/chousui-zhang/dan",
                                 "name"     :  "���ĵ�",
                                 "sk1"      :  "chousui-zhang",
                                 "lv1"      :  140,
                                 "sk2"      :  "force",
                                 "lv2"      :  140,
                                 "sk3"      :  "poison",
                                 "lv3"      :  140,
                                 "sk4"      :  "throwing",
                                 "lv4"      :  140,
                                 "shen"     :  -22000,
                                 "neili"    :  1800,
                                 "gongxian" :  950 ]));
                  break;

             case "��������":
                 return MASTER_D->teach_pfm(me, this_object(),
                               (["perform"  :  "can_perform/chousui-zhang/tao",
                                 "name"     :  "��������",
                                 "sk1"      :  "chousui-zhang",
                                 "lv1"      :  220,
                                 "sk2"      :  "poison",
                                 "lv2"      :  250,
                                 "sk3"      :  "huagong-dafa",
                                 "lv3"      :  220,
                                 "shen"     :  -38000,
                                 "neili"    :  3000,
                                 "gongxian" :  1200 ]));
                  break;
   
             case "��˿��" :
                return MASTER_D->give_item(me, this_object(),
                               (["item"     :  SUO,
                                 "master"   :  1,
                                 "sk1"      :  "chanhun-suo",
                                 "lv1"      :  140,
                                 "shen"     :  -30000 ]));
                  break;
                               
             default : 
                  return 0;
                           
        }
}

void clear_xiangliao_flag()
{
        if (this_player()->query_temp("get_xiangliao"))
               this_player()->delete_temp("get_xiangliao");
      
        return;
}