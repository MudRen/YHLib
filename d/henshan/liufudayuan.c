inherit ROOM;

int do_knock(string arg);

void create()
{
        set("short", "������Ժ");
        set("long", @LONG
������Ժ�����ڼ��źܶ཭�����ͣ�ԭ���������������
��ϴ�ֵĺ����ӡ�����ү���ں�����Ե�ܺã�����������Ȼ��
�٣���Ժ���Ѱ��˺ܶ������ӣ������������������֡�������
��һ�����������쳣�������������ǳ���ʲô���顣
LONG);
        set("exits", ([
               "north"  : __DIR__"liufudating",
               "out"    : __DIR__"liufugate",
        ]));

        set("objects", ([
                __DIR__"npc/dao-ke"  : 2,
                __DIR__"npc/jian-ke" : 4,
                __DIR__"npc/haoke"   : 2,
        ]));

        setup();
	replace_program(ROOM);
}
