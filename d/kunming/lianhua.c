#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����������壬����ʯ�ֵķ�⾡���۵ף��ۼ����߲�Զ
����һ����(zi)������Ͽ���һСʫ (shi)�����¹�����ֻ��
����һ̶��ˮ�������澰�����������������·ת���쾳��
������ʹ���Ķ���ۣ��ֶ������ӡ�
LONG);
        set("outdoors", "kunming");

        set("exits", ([                
                "southdown" : __DIR__"shilin2",
                "up" : __DIR__"wfting",
        ]));

        set("item_desc", ([
                     "zi" : WHT "\n         �������� \n"
                             "         ��    �� \n"
                             "         �� �� �� \n"
                             "         ��    �� \n"
                             "         �� �� �� \n"
                             "         ��    �� \n"
                             "         �� �� �� \n"
                             "         ��    �� \n"
                             "         �� һ �� \n"
                             "         ��    �� \n"
                             "         �� �� �� \n"
                             "         ��    �� \n"
                             "         �� �� �� \n"
                             "         ��    �� \n"
                             "         �������� \n\n\n" NOR,

                     "shi" : HIR "\n\n\n            �ʵ�ֱ�����칤\n\n"
                             "            һ���������ڷ�\n\n"
                             "            ��������Ӻ�ˮ\n\n"
                             "            ����˫�ָ����\n\n\n" NOR,
                  ]));

        set("objects", ([
                "/d/beijing/npc/youke" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
