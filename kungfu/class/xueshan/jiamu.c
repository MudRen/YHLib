#include <ansi.h>
#include "xueshan.h"
#include "tobebonze.h"

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("��ľ���", ({ "jiamu huofo", "huofo", "jiamu" }));
        set("long", @LONG
��ľ����Ǵ������е��ĸ�ɮ���Է��о���
���о�������һ����ɫ���ģ�ͷ��ɮñ��Ŀ
����磬�ƺ���������
LONG); 
        set("title", "�����»��"); 
        set("gender", "����");
        set("class", "bonze");
        set("age", 38);
        set("attitude", "peaceful");
        set("shen_type", -1);

        set("str", 35);
        set("int", 20);
        set("con", 25);
        set("dex", 20);

        set("max_qi", 3500);
        set("max_jing", 2500);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 150);
        set("combat_exp", 800000);

        set_skill("force", 180);
        set_skill("mizong-neigong", 180);
        set_skill("dodge", 160);
        set_skill("shenkong-xing", 160);
        set_skill("hammer", 160);
        set_skill("dali-chu", 160);
        set_skill("xiangmo-chu", 160);
        set_skill("hand", 180);
        set_skill("dashou-yin", 180);
        set_skill("cuff", 180);
        set_skill("yujiamu-quan", 180);
        set_skill("parry", 180);
        set_skill("lamaism", 200);
        set_skill("literate", 200);
        set_skill("sanscrit", 200);
        set_skill("martial-cognize", 180);

        map_skill("force", "mizong-neigong");
        map_skill("dodge", "shenkong-xing");
        map_skill("parry", "xiangmo-chu");
        map_skill("hammer", "xiangmo-chu");
        map_skill("hand", "dashou-yin");
        map_skill("cuff", "yujiamu-quan");

        prepare_skill("cuff", "yujiamu-quan");
        prepare_skill("hand", "dashou-yin");

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "hand.yin" :),
                (: perform_action, "cuff.jiang" :),
                (: exert_function, "recover" :),
        }));

        create_family("������", 2, "����");

        set("inquiry",([
                "���" : (: ask_for_join :),
                "����" : (: ask_for_join :),
        ]));

        setup(); 
 
        carry_object("/d/xueshan/obj/y-jiasha")->wear(); 
        carry_object("/d/xueshan/obj/sengmao")->wear();
} 

void attempt_apprentice(object ob) 
{
        if (! permit_recruit(ob))
                return;

        command("say ƶɮֻ�з𷨣�������ͽ��");
}
