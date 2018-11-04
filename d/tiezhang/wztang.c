#include <ansi.h>

inherit ROOM;
string look_bian();

void create()
{
        set("short", HIY "��ָ��" NOR);
        set("long", @LONG
����һ����ȫ�û��������ɵĴ�����͸��������˵ĺ�������������û
�д������Ե���ɭ�ڰ������Ե�ǽ���ϲ��������ƵĻ�ѣ�ɢ�������ɫ��
�������ž��Ĵ����в�ʱ��������ž��ȼ���������������аڷ��Ű�����
���������Է�����ʮ�������ӣ�ֻ���������д���ʱ�������Ż��������벿
�����顣�������ǽ�Ϲ���һ���ƽ�ĺ���(bian)��������һ��С��ͨ���
�档
LONG );

        set("item_desc", ([ 
                "bian"       :       (: look_bian :),
        ]));

        set("exits", ([ 
                "east" : __DIR__"zoulang-1",
                "southdown" : __DIR__"guangchang",
                "west" : __DIR__"zoulang-2",
                "north" : __DIR__"hxfang",
        ]));
        set("objects", ([ 
                CLASS_D("tiezhang") + "/qiuqianren" : 1,
                __DIR__"npc/xiaotong" : 2,
        ]));

        set("no_clean_up", 0);
        set("valid_startroom", 1);
        setup();
}

string look_bian()
{
    return
    "\n"
              HIY "          ####################################\n"
                  "          ####                            ####\n"
                  "          ####    ��    ָ    ��    ��    ####\n"  
                  "          ####                            ####\n"
                  "          ####################################\n\n\n\n\n\n\n" NOR;
    "\n";
}
