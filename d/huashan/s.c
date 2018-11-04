#include <ansi.h>

inherit ROOM;
#define TSROB __DIR__"tsr_dugu-jiujian"

string look_door();

void create()
{
        string msg;

        set("short", "�ͱ�");
        set("exits", ([
                "hole1" : __DIR__"lockroom1",
                "hole2" : __DIR__"lockroom2",
                "hole3" : __DIR__"lockroom3",
                "hole4" : __DIR__"lockroom4",
                "hole5" : __DIR__"lockroom5",
                "hole6" : __DIR__"lockroom6",
                "out"   : __DIR__"shandong",
        ]));

        set("long", @LONG
���������ͱڣ�ֻ��ǰ����Ȼ��һ��ɽ�������Ǳ�һ����
���ʯ�ţ�door����ס�ˣ�ʯ����ȴ����������״���ػ�棨huoju���� 
ϸ��ʯ����Χ��ֻ�������������˹�����Сɽ����
LONG);

        set("item_desc", ([
               "door"   : (: look_door :),
               "huoju"  : HIR "��Щ��濴������֣��ƺ�������ʲô���أ�\n" NOR,
        ]));

        set("no_clean_up", 0);
        setup();
}

void init()
{
        object tsrob;
        if (! tsrob = find_object(TSROB))
                 tsrob = load_object(TSROB);
        
}

string look_door()
{
        object ob;
        int n;
        string opened, msg, temp;

        mapping change_num = ([
               "1" : "һ",
               "2" : "��",
               "3" : "��",
               "4" : "��",
               "5" : "��",
               "6" : "��",
        ]);

        ob = find_object(TSROB);

        if (! objectp(ob))
               return "TSR �������������ʦ��ϵ��\n";

        opened = ob->query("lock/opened");

        if (opened == "" || ! stringp(opened))
               return "ֻ��ʯ�Ž��գ�����������ѻ�棨huoju��������Ϩ���ˣ�\n";

        if (ob->query("lock/unlocked") && sizeof(opened) == 6)
               return NOR + WHT "\nֻ��ʯ��������£����ѻ���յ�������һ�����¶�˳�����\n" NOR;

        msg = HIC "ֻ��ʯ�Ž��գ���";
        for (n = 0; n < sizeof(opened); n ++)
        {
              temp = opened[n..n];
              msg += change_num[temp];
              if (n < sizeof(opened) - 1)msg += "��" ;              
        }
        msg += "�ѻ��ȼ���ţ�\n" NOR;
 
        return msg;

}

