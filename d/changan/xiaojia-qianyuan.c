//Room: xiaojia-qianyuan.c

inherit ROOM;
void create ()
{
        set ("short", "����ǰԺ");
        set ("long", @LONG
�������һ�������ûʵľ�լԺ�����������ǰ��������������
ͷ�ߴ��ʯʨ�ӡ����Ϲ���������������Ȼд�Ŵ��ġ������֡�
LONG);
        set("exits", ([
        	"west" : __DIR__"liande-dadao5",
        	"east" : __DIR__"xiaojiadt",
        ]));
        set("objects", 
        ([ //sizeof() == 1
        	__DIR__"npc/guanjia" : 1,
        ]));

        set("outdoors", "changan");
        setup();
        replace_program(ROOM);
}
