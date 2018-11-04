// Room: /d/huashan/sgyhole.c

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
����һ���������۵�ɽ�������������ʯ����ȴ��������
�����������Ѿ�ʧ���ľ�����С�������ʯ��(wall)�Ϻܶ�С
�ˣ�ȫ�����������ƣ������������֮������ʮ�����
LONG );
        set("exits", ([ /* sizeof() == 4 */
            "southup"   : __DIR__"sgyhole2",
            "north"     : __DIR__"sgyhole4",
        ]));
        set("item_desc", ([ 
            "wall" : @TEXT

       o    | o      o    \ o      o      o     <o     <o>
    --^|\    ^|^  --v|^    v|v    |/v   \|X|    \|      |
       /\     >\    /<      >\    /<      >\    /<      >\

       o>     o      o      o      o      o      o      o
       \ __   x     </     <|>    </>    <\>    <)>     |\__
      /<      >\    /<      >\    /<      >\     >>     L

TEXT
        ]));

        setup();
}
void init()
{
        add_action("do_mianbi", "mianbi");
}

int do_mianbi()
{
        object ob;
        int c_skill;

        ob = this_player();

        c_skill = (int)ob->query_skill("poyang-jian", 1);


        if (!ob->query("can_perform/poyang-jian/long"))
        {
                write("�����ʯ���ϵ����ݶ�����Թ�����£�һʱ������ᡣ\n");
                return 1;
        }

        if (ob->query("real_perform/poyang-jian/long"))
        {
                write("�����ʯ���ϵ����ݶ�����Թ��ڷ�ǳ��\n");
                return 1;
        }

        if (ob->query("combat_exp") < 1000000)
        {
                write("���ʵս���鲻�㣬�޷�����ʯ�����ݡ�\n");
                return 1; 
        }

        if (c_skill < 160)
        {
                write("���о��˰��죬ʼ���޷�����͸ʯ���ϵ����ݡ�\n");
                return 1; 
        }

        if (ob->query("jing") < 80)
        {
                write("�㾫�����ܼ��У������޷�����ʯ�����ݡ�\n",ob);
                return 1; 
        }
      
        if (random(15) != 1)
        {
        
                write("�������ʯ��������˼�����ã��ԡ�����������"
                               "�����������򣬵�������಻��֮����\n", ob);
                ob->start_bisy(2);
                return 1;
        }

        message_sort(HIW"\n$N" HIW"�����ʯ��������˼����Ȼ��һ����̾����"
                     "�ෲ��������ӿ����ͷ��$N" HIW "���ڽ�������������"
                     "����������Ӵ��������ǡ�\n", ob);

        if (ob->can_improve_skill("sword"))
                 ob->improve_skill("sword", 1500000);   
        if (ob->can_improve_skill("poyang-jian"))
                 ob->improve_skill("poyang-jian", 1500000);     
        if (ob->can_improve_skill("martial-cognize"))
                 ob->improve_skill("martial-cognize", 1500000);
    
        write(HIC "��ѧ���ˡ�������������\n" NOR);
        ob->set("real_perform/poyang-jian/long", 1);
        ob->receive_damage("jing", 75);
        ob->start_busy(2);
        return 1;
}
