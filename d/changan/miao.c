//Room: miao.c

inherit ROOM;

void create ()
{
        set ("short", "������");
        set ("long", @LONG
����һ��������ˣ������Ͳ������ھ��Եø�С�ˣ�����С�޼�
�������������ա�û��������������һ�ǣ����Ҹպ����������ڵĵ�
���������������ܵ�ɽ��������õġ���Ҳ��֪�Ǳ�����һλ������
�ܵ��������������۾��ɵ�����öͭ�壬���һ����ڷ��⡣
LONG);
        set("exits", ([
        	"west"   : __DIR__"yongtai-dadao4",
        ]));
        set("objects", ([
        	__DIR__"npc/keeper"   : 1,
        ]));

        setup();
        replace_program(ROOM);
}