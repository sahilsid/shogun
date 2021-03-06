/*
 * This software is distributed under BSD 3-clause license (see LICENSE file).
 *
 * Authors: Soeren Sonnenburg, Heiko Strathmann, Sergey Lisitsyn, 
 *          Evgeniy Andreev, Fernando Iglesias, Soumyajit De, Chiyuan Zhang, 
 *          Thoralf Klein, Evan Shelhamer, Yuyu Zhang
 */

#ifndef __DATATYPE_H__
#define __DATATYPE_H__

#include <shogun/io/SGIO.h>
#include <shogun/lib/common.h>
#include <shogun/lib/config.h>

#define PT_NOT_GENERIC	PT_SGOBJECT

namespace shogun
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS
enum EContainerType
{
	CT_SCALAR=0,
	CT_VECTOR=1,
	CT_MATRIX=2,
	CT_NDARRAY=3,
	CT_SGVECTOR=4,
	CT_SGMATRIX=5,
	CT_UNDEFINED=6
};

enum EStructType
{
	ST_NONE=0,
	ST_SPARSE=1,
	ST_UNDEFINED=2
};

enum EPrimitiveType
{
	PT_BOOL=0,
	PT_CHAR=1,
	PT_INT8=2,
	PT_UINT8=3,
	PT_INT16=4,
	PT_UINT16=5,
	PT_INT32=6,
	PT_UINT32=7,
	PT_INT64=8,
	PT_UINT64=9,
	PT_FLOAT32=10,
	PT_FLOAT64=11,
	PT_FLOATMAX=12,
	PT_SGOBJECT=13,
	PT_COMPLEX128=14,
	PT_UNDEFINED=15
};

/** Returns string representation of primitive type
 * @param pt primitive type
 * @return string for primitive type
 */
std::string ptype_name(EPrimitiveType pt);
#endif

/** @brief Datatypes that shogun supports. */
struct TSGDataType
{
	/** container type */
	EContainerType m_ctype;
	/** struct type */
	EStructType m_stype;
	/** primitive type */
	EPrimitiveType m_ptype;

	/** length y */
	index_t *m_length_y;
	/** length x */
	index_t *m_length_x;

	/** constructor
	 * @param ctype
	 * @param stype
	 * @param ptype
	 */
	explicit TSGDataType(EContainerType ctype, EStructType stype,
						 EPrimitiveType ptype);
	/** constructor
	 * @param ctype
	 * @param stype
	 * @param ptype
	 * @param length
	 */
	explicit TSGDataType(EContainerType ctype, EStructType stype,
						 EPrimitiveType ptype, index_t* length);
	/** constructor
	 * @param ctype
	 * @param stype
	 * @param ptype
	 * @param length_y
	 * @param length_x
	 */
	explicit TSGDataType(EContainerType ctype, EStructType stype,
						 EPrimitiveType ptype, index_t* length_y,
						 index_t* length_x);

	/** equality */
	bool operator==(const TSGDataType& a);
	/** inequality
	 * @param a
	 */
	inline bool operator!=(const TSGDataType& a)
	{
		return !(*this == a);
	}

	/** to string
	 * @param dest
	 * @param n
	 */
	void to_string(char* dest, size_t n) const;

	/** size of stype */
	size_t sizeof_stype() const;
	/** size of ptype */
	size_t sizeof_ptype() const;

	/** get the size of the primitive type ptype
	 *
	 * @param ptype the primitive type
	 * @return its size
	 */
	static size_t sizeof_ptype(EPrimitiveType ptype);

	/** get the size of the structured type stype that internally uses the
	 * primitive type ptype as type
	 *
	 * @param stype the structured type
	 * @param ptype the primitive type
	 * @return its size
	 */
	static size_t sizeof_stype(EStructType stype, EPrimitiveType ptype);

	/** size of sparse entry
	 * @param ptype
	 */
	static size_t sizeof_sparseentry(EPrimitiveType ptype);

	/** offset of sparse entry
	 * @param ptype
	 */
	static size_t offset_sparseentry(EPrimitiveType ptype);

	/** stype to string
	 * @param dest
	 * @param stype
	 * @param ptype
	 * @param n
	 */
	static void stype_to_string(char* dest, EStructType stype,
	                            EPrimitiveType ptype, size_t n);
	/** ptype to string
	 * @param dest
	 * @param ptype
	 * @param n
	 */
	static void ptype_to_string(char* dest, EPrimitiveType ptype,
	                            size_t n);
	/** string to ptype
	 * @param ptype
	 * @param str
	 */
	static bool string_to_ptype(EPrimitiveType* ptype,
	                            const char* str);

	/** get size
	 * @return size of type in bytes
	 */
	size_t get_size();

	/** get num of elements
	 * @return number of (matrix, vector, scalar) elements of type
	 */
	int64_t get_num_elements();
};
}
#endif /* __DATATYPE_H__  */
