//Room: bank.c

#include <ansi.h>

inherit ROOM;

void create ()
{
        set ("short", "�ĺ�Ǯׯ");
        set ("long", @LONG
���ǳ����ǵ�һ�����ֺ�Ǯׯ���ϰ���ɽ���ˣ����Ǯׯ��������
����������ʱ�Ϳ�ʼ����һֱ�����������Ǯׯ�������ǳ��ã���
����ȫ�����ض����˷ֵꡣ�����е���Ʊͨ��ȫ����Ǯׯ���ſڹ���һ
������(paizi)��
LONG);
        set("item_desc", ([
        	"paizi": 
HIG"��Ǯׯ�ṩ�ķ����У�\n"NOR
HIC"--------------------------------\n"NOR
HIG"check(chazhang)        ����\n"NOR 
HIC"--------------------------------\n"NOR
HIG"deposit(cun)           ���\n"NOR
HIC"--------------------------------\n"NOR
HIG"withdraw(qu)           ȡ��\n"NOR
HIC"--------------------------------\n"NOR
HIG"convert(duihuan)       �һ�Ǯ��\n"NOR
HIC"--------------------------------\n"NOR

        ]) );
        set("exits", 
        ([ //sizeof() == 1
        	"south" : __DIR__"qixiang4",
        ]));
        set("objects", 
        ([ //sizeof() == 1
        	__DIR__"npc/tiegongji" : 1,
        ]));

	set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
