inherit NPC;
inherit F_MASTER;

#include <command.h>
#include <ansi.h>
#include "emei.h"

void create()
{
        set_name("������", ({ "zhou zhiruo","zhiruo","zhou"}));
        set("long", "���Ƕ����ɵĵ��Ĵ����ŵ��ӡ�ֻ����һ��\n"
                    "���������ס�����һ�������ѡ��������\n"
                    "����Ц�д���Щ�����Ρ�\n");
        set("gender", "Ů��");
        set("age", 20);
        set("attitude", "peaceful");
        set("shen_type", 1);

        set("inquiry",([
                "���"     : "������ȣ����԰ɡ�",
                "����"     : "Ҫ�������ҵ�ʦ����ȥ��",
                "����"     : "���ġ�����Ҳ���ң�",
                "���޼�"   : "������Ķ����ļһ����Ҳ��Ҫ������",
                "����"     : "��Ҫ���������ӣ�",
                "���콣"   : "���첻����˭�����棿����",
                "������"   : "�������ֳ��ۣ��������ˡ�",
                "���ʦ̫" : "ʦ�����Ҷ�����ɽ���ҽ������Իر���",
                "�����澭" : "����ʲô������������ǵ�һ����˵��",
        ]));

        set("str", 22);
        set("int", 32);
        set("con", 26);
        set("dex", 24);

        set("max_qi", 5000);
        set("max_jing", 3000);
        set("neili", 6000);
        set("max_neili", 6000);
        set("jingli", 2000);
        set("max_jingli", 2000);
        set("jiali", 200);
        set("combat_exp", 2500000);

        set_skill("force", 260);
        set_skill("emei-xinfa", 180);
        set_skill("yijin-duangu", 260);      // �׽�͹�
        set_skill("linji-zhuang", 200);
        set_skill("dodge", 260);
        set_skill("shexing-lifan", 260);     // �����귭
        set_skill("zhutian-bu", 180);
        set_skill("finger", 180);
        set_skill("tiangang-zhi", 180);
        set_skill("hand", 180);
        set_skill("jieshou-jiushi", 180);
        set_skill("strike", 260);
        set_skill("jinding-zhang", 180);
        set_skill("sixiang-zhang", 180);
        set_skill("cuixin-zhang", 260);      // ������
        set_skill("claw", 260);
        set_skill("jiuyin-baiguzhao", 260);  // �����׹�צ
        set_skill("whip", 260);
        set_skill("yinlong-bian", 260);      // �����޷�
        set_skill("sword", 180);
        set_skill("emei-jian", 180);
        set_skill("yitian-jian", 180);
        set_skill("blade", 180);
        set_skill("yanxing-dao", 180);
        set_skill("parry", 260);
        set_skill("martial-cognize", 200);
        set_skill("literate", 200);
        set_skill("mahayana", 100);
        set_skill("buddhism", 100);

        map_skill("force", "yijin-duangu");
        map_skill("dodge", "shexing-lifan");
        map_skill("finger", "tiangang-zhi");
        map_skill("hand", "jieshou-jiushi");
        map_skill("strike", "cuixin-zhang");
        map_skill("claw", "jiuyin-baiguzhao");
        map_skill("whip", "yinlong-bian");
        map_skill("sword", "yitian-jian");
        map_skill("blade", "yanxing-dao");
        map_skill("parry", "yinlong-bian");

        prepare_skill("strike", "cuixin-zhang");
        prepare_skill("claw", "jiuyin-baiguzhao");

        create_family("������", 4, "���ŵ���");

        set("no_teach", ([
                "linji-zhuang"     : "��ѧ�ټ�ʮ��ׯ����ʦ��ȥ��",
                "shexing-lifan"    : "�����귭����Ҳ�����书�������ֵ���������˼�ġ�",
                "yijin-duangu"     : "��˵������ʲô�����������ͷһ����˵��",
                "cuixin-zhang"     : "�����ƣ������ֹ����˵ģ��������书�ҿɲ��ᡣ",
                "jiuyin-baiguzhao" : "�����׹�צ������ʲô�书�������������Ҿ�ë���Ȼ��",
                "yinlong-bian"     : "��ֻ�ὣ���͵������޷�ʦ������û�̹��ҡ�",
        ]));

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "claw.duo" :),       // ��������
                (: perform_action, "claw.jie" :),       // ����ɲ��ץ
                (: perform_action, "strike.cuixin" :),  // ������Ԫ��
                (: perform_action, "whip.jiao" :),      // �������Ծ�
                (: perform_action, "dodge.guiyuan" :),  // ������Ԫ��
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
                (: exert_function, "shield" :),
        }));

        setup();
//        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/city/npc/cloth/sha-dress")->wear();
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query_int() < 45)
        {
                command("say ��λ" + RANK_D->query_respect(ob) + "�������ʲ���һ�㡣");
                command("say �����д���Ǳ���������Ȼ�ȥĥ��ĥ����");
                return;
        }

        command("say " + ob->query("name") + "������ô��������Ϊ����������ɡ�\n");
        command("recruit " + ob->query("id"));
}
