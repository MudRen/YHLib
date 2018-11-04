#include <ansi.h>
#include "honghua.h"

inherit NPC;
inherit F_MASTER;
inherit F_GUARDER;

void create()
{
        set_name("����ͬ", ({ "yu yutong", "yu","yutong" }));
        set("title", "�컨��ʮ�ĵ���");
        set("nickname", HIY "������" NOR);
        set("long", "һ������������ü��Ŀ�㣬����Ӣ����������\n"
                    "����ͬ�˽��������ӵܣ��й���š�������\n"
                    "���һ�Һ�����һ��صأ���˾�����ҵ�\n"
                    "�����ֱ����Ž���ݺ����������С�����ͬ\n"
                    "һ�����ߣ�������Ե��������Ϊʦ������ϰ\n"
                    "�䣬������ʿ���������Ӵ���������������\n"
                    "���˺컨�ᡣ��Ϊ�˻������ɣ���ʶ������\n"
                    "̸���ڻ����������ķ�����̽ѶϢְ֮��\n");
        set("gender", "����");
        set("class", "scholar");
        set("age", 20);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("per", 27);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        
        set("qi", 2800);
        set("max_qi", 2800);
        set("jing", 2000);
        set("max_jing", 2000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 120);
        set("combat_exp", 1000000);
        set("score", 10000);

        set_skill("force", 140);
        set_skill("taiji-shengong", 140);
        set_skill("unarmed", 140);
        set_skill("xuangong-quan", 140);
        set_skill("dodge", 140);
        set_skill("tiyunzong", 140);
        set_skill("sword", 140);
        set_skill("rouyun-jian", 140);
        set_skill("parry", 140);
        set_skill("throwing", 140);
        set_skill("furong-jinzhen", 140);
        set_skill("martial-cognize", 100);
        set_skill("literate", 200);

        map_skill("force"  , "taiji-shengong");
        map_skill("sword"  , "rouyun-jian");
        map_skill("unarmed" , "xuangong-quan");
        map_skill("dodge"  , "tiyunzong");
        map_skill("parry"  , "rouyun-jian");
        map_skill("throwing"  , "furong-jinzhen");

        prepare_skill("unarmed", "xuangong-quan");

        set("coagents", ({
                ([ "startroom" : "/d/kaifeng/road4",
                   "id"        : "lu feiqing" ]),
        }));

        set("guarder", ([
                "refuse_other": CYN "$N" CYN "��$n" CYN "��ȵ���"
                                "������������������ȥ���á�" NOR,
                "refuse_carry": CYN "$N" CYN "��$n" CYN "�ȵ�����"
                                "��Ȼ������ȥ��������ʲô��˼��" NOR,
        ]));

        create_family("�컨��", 4, "����");

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.xuan" :),
                (: perform_action, "sword.tao" :),
                (: perform_action, "throwing.xian" :),
                (: exert_function, "shield" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );

        setup();
        carry_object("/clone/cloth/jinduan")->wear();
        carry_object("/d/kaifeng/npc/obj/jindi")->wield();
        set_temp("handing", carry_object("/d/kaifeng/npc/obj/jinzhen"));
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        command("en");
        command("say �Ҳ���ͽ���������༸λ���ҵĺ��ˡ�");
}
