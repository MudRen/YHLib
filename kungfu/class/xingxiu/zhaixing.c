// zhaixing.c ժ����
// modify by rcwiz 2003

inherit NPC;
inherit F_MASTER;
inherit F_GUARDER;

#include "xingxiu.h"
#include <ansi.h>

string ask_me();
string ask_book();

void create()
{
        set_name("ժ����", ({ "zhaixing zi", "zhaixing", "zi" }));
        set("nickname", HIR "�����ɴ�ʦ��" NOR);
        set("long", 
                "�����Ƕ�����Ĵ���ӡ������ɴ�ʦ��ժ���ӡ�\n"
                "����ʮ���꣬�����������۹���͸��һ˿����֮����\n");
        set("gender", "����");
        set("age", 35);
        set("attitude", "peaceful");
        set("class", "fighter");
        set("str", 26);
        set("int", 28);
        set("con", 26);
        set("dex", 26);
        
        set("max_qi", 3400);
        set("max_jing", 1800);
        set("neili", 5800);
        set("max_neili", 5800);
        set("jiali", 80);
        set("combat_exp", 420000);
        set("shen_type", -1);

        set_skill("force", 140);
        set_skill("huagong-dafa", 140);
        set_skill("guixi-gong", 140);
        set_skill("throwing", 120);
        set_skill("feixing-shu", 120);
        set_skill("dodge", 120);
        set_skill("zhaixing-gong", 120);
        set_skill("whip", 120);
        set_skill("chanhun-suo", 120);
        set_skill("strike", 120);
        set_skill("chousui-zhang", 120);
        set_skill("claw", 120);
        set_skill("sanyin-wugongzhao", 120);
        set_skill("parry", 120);
        set_skill("staff", 120);
        set_skill("tianshan-zhang", 120);
        set_skill("poison", 140);
        set_skill("medical", 120);
        set_skill("xingxiu-qishu", 140);

        set("no_teach", ([
                "huagong-dafa" : "������Ҫ�������Դ��ڡ�",
        ]));

        map_skill("force", "huagong-dafa");
        map_skill("dodge", "zhaixing-gong");
        map_skill("strike", "chousui-zhang");
        map_skill("claw", "sanyin-wugongzhao");
        map_skill("parry", "chousui-zhang");
        map_skill("throwing", "feixing-shu");
        map_skill("whip", "chanhun-suo");
        map_skill("staff", "tianshan-zhang");

        prepare_skill("strike", "chousui-zhang");
        prepare_skill("claw", "sanyin-wugongzhao");

        set("coagents", ({
                ([ "startroom" : "/d/xingxiu/riyuedong",
                   "id"        : "ding chunqiu", ]),
        }));

        set("inquiry", ([
                "���ĵ�"    : (: ask_me :),
                "�ؼ�"      : (: ask_book :),
                "��ɽ����"  : (: ask_book :),
        ]));
        set("dan_count", 1);
        set("book_count", 1);

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "claw.zhua" :),
                (: perform_action, "strike.tao" :),
                (: perform_action, "strike.shi" :),
                (: perform_action, "strike.dan" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );

        set_temp("apply/attack", 150);
        set_temp("apply/defense", 150);
        set_temp("apply/damage", 150);
        set_temp("apply/unarmed_damage", 150);

        create_family("������", 2, "����");

        setup();
        carry_object("/clone/weapon/lianzi")->wield();
}

void attempt_apprentice(object ob)
{
        if (ob->query("shen") > 0)
        {
             command("heng");
             command("say ����������������Щ�������ˣ��㻹�ǻ�ȥ�ɣ�");
             return;
        }
        command("say �ðɣ��Ҿ��������ˡ�");
        welcome(ob);
        command("recruit " + ob->query("id"));
}

string ask_me()
{
        mapping fam; 
        object ob;
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
                return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��\n";

        if (query("dan_count") < 1)
                return "�������ˣ�û�����ĵ��ˡ�\n";

        add("dan_count", -1);
        ob = new("/d/xingxiu/obj/lianxindan");
        ob->move(this_player());
        return "��Щ���ĵ������õ��˰ɡ�\n";
}

string ask_book()
{
        mapping fam; 
        object ob;
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
                return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��\n";

        if (query("book_count") < 1)
                return "�������ˣ�����ûʲôʣ���ˡ�\n";

        add("book_count", -1);
        ob = new("/clone/book/throw_book");
        ob->move(this_player());
        return "�ðɣ��Ȿ�����û�ȥ�úÿ����ɡ�\n";
}

int accept_ask(object me, string topic)
{
        switch(topic)
        {      
             case "��������":
                 return MASTER_D->teach_pfm(me, this_object(),
                               (["perform"  :  "can_perform/tianshan-zhang/fugu",
                                 "name"     :  "��������",
                                 "sk1"      :  "tianshan-zhang",
                                 "lv1"      :  60,
                                 "shen"     :  -2200,
                                 "gongxian" :  80,
                                 "force"    :  80 ]));
                  break;

             case "��ѩ�׷�":
                 return MASTER_D->teach_pfm(me, this_object(),
                               (["perform"  :  "can_perform/tianshan-zhang/xue",
                                 "name"     :  "��ѩ�׷�",
                                 "sk1"      :  "tianshan-zhang",
                                 "lv1"      :  60,
                                 "shen"     :  -22000,
                                 "gongxian" :  80,
                                 "force"    :  80 ]));
                  break;

             case "���컨��":
                 return MASTER_D->teach_pfm(me, this_object(),
                               (["perform"  :  "can_perform/feixing-shu/hua",
                                 "name"     :  "���컨��",
                                 "sk1"      :  "feixing-shu",
                                 "lv1"      :  100,
                                 "sk2"      :  "force",
                                 "lv2"      :  120,
                                 "shen"     :  -5500,
                                 "gongxian" :  400 ]));
                  break;

             case "������":
                 return MASTER_D->teach_pfm(me, this_object(),
                               (["perform"  :  "can_perform/chanhun-suo/suo",
                                 "name"     :  "������",
                                 "sk1"      :  "chanhun-suo",
                                 "lv1"      :  70,
                                 "sk2"      :  "force",
                                 "lv2"      :  120,
                                 "shen"     :  -6500,
                                 "gongxian" :  400 ]));
                  break;

             case "������צ":
                 return MASTER_D->teach_pfm(me, this_object(),
                               (["perform"  :  "can_perform/sanyin-wugongzhao/zhua",
                                 "name"     :  "������צ",
                                 "sk1"      :  "sanyin-wugongzhao",
                                 "lv1"      :  100,
                                 "sk2"      :  "force",
                                 "lv2"      :  100,
                                 "shen"     :  -7000,
                                 "gongxian" :  500 ]));
                  break;

             case "��ʬ��":
                 return MASTER_D->teach_pfm(me, this_object(),
                               (["perform"  :  "can_perform/chousui-zhang/shi",
                                 "name"     :  "��ʬ��",
                                 "sk1"      :  "chousui-zhang",
                                 "lv1"      :  140,
                                 "sk2"      :  "force",
                                 "lv2"      :  120,
                                 "sk3"      :  "poison",
                                 "lv3"      :  150,
                                 "sk4"      :  "throwing",
                                 "lv4"      :  120,                                 
                                 "shen"     :  -10000,
                                 "neili"    :  1200,
                                 "gongxian" :  500 ]));
                  break;

             default : 
                  return 0;
                           
        }
}

void unconcious()
{
        die();
}

